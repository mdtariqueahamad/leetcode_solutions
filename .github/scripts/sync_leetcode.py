import os
import sys
import time
import requests
from pathlib import Path

GRAPHQL_URL = "https://leetcode.com/graphql/"

# Fetch authentication from environment variables
SESSION = os.environ.get("LEETCODE_SESSION")
CSRF_TOKEN = os.environ.get("LEETCODE_CSRF_TOKEN")

if not SESSION or not CSRF_TOKEN:
    print("ERROR: LeetCode session cookies are missing. Check your GitHub Secrets.")
    sys.exit(1)

# Resolves to repo root assuming script is at /.github/scripts/sync_leetcode.py
REPO_ROOT = Path(__file__).resolve().parents[2]
PROBLEMS_DIR = REPO_ROOT / "leetcode_problems"
PROBLEMS_DIR.mkdir(parents=True, exist_ok=True)

# Set up HTTP session with cookies
http = requests.Session()
http.cookies.set("LEETCODE_SESSION", SESSION, domain=".leetcode.com")
http.cookies.set("csrftoken", CSRF_TOKEN, domain=".leetcode.com")

HEADERS = {
    "Content-Type": "application/json",
    "Origin": "https://leetcode.com",
    "Referer": "https://leetcode.com/",
    "X-CSRFToken": CSRF_TOKEN,
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36",
}

def graphql(operation_name, query, variables=None):
    payload = {"operationName": operation_name, "query": query, "variables": variables or {}}
    response = http.post(GRAPHQL_URL, headers=HEADERS, json=payload, timeout=30)
    
    if response.status_code != 200:
        raise RuntimeError(f"LeetCode HTTP Error {response.status_code}")
        
    body = response.json()
    if body.get("errors"):
        raise RuntimeError(f"GraphQL error: {body['errors']}")
        
    return body.get("data", {})

SOLVED_QUERY = """
query problemsetQuestionList(\(categorySlug: String,\)limit: Int, \(skip: Int,\)filters: QuestionListFilterInput) {
    problemsetQuestionList: questionList(categorySlug: \(categorySlug, limit:\)limit, skip: \(skip, filters:\)filters) {
        total: totalNum
        questions: data {
            frontendId: questionFrontendId
            title
            titleSlug
            difficulty
        }
    }
}
"""

SUBMISSIONS_QUERY = """
query submissionList(\(offset: Int!,\)limit: Int!, $questionSlug: String!) {
    questionSubmissionList(offset: \(offset, limit:\)limit, questionSlug: $questionSlug) {
        submissions {
            id
            statusDisplay
            lang
        }
    }
}
"""

SUBMISSION_DETAILS_QUERY = """
query submissionDetails($submissionId: Int!) {
    submissionDetails(submissionId: $submissionId) {
        code
    }
}
"""

# Map LeetCode language tags to correct file extensions
EXTENSIONS = {
    "python": "py", "python3": "py", "pythondata": "py",
    "cpp": "cpp", "java": "java", "c": "c", "csharp": "cs",
    "javascript": "js", "typescript": "ts", "ruby": "rb",
    "swift": "swift", "golang": "go", "scala": "scala",
    "kotlin": "kt", "rust": "rs", "php": "php", "dart": "dart",
    "mysql": "sql", "mssql": "sql", "oraclesql": "sql", "postgresql": "sql",
    "bash": "sh", "racket": "rkt", "erlang": "erl", "elixir": "ex"
}

def main():
    print("Fetching list of solved problems from LeetCode...")
    skip = 0
    limit = 100
    all_questions = []

    # 1. Fetch all Accepted problems
    while True:
        data = graphql("problemsetQuestionList", SOLVED_QUERY, {
            "categorySlug": "", "skip": skip, "limit": limit, "filters": {"status": "AC"}
        })
        result = data.get("problemsetQuestionList", {})
        questions = result.get("questions", [])

        if not questions:
            break

        all_questions.extend(questions)
        skip += limit
        
        if len(all_questions) >= result.get("total", 0):
            break

    print(f"Total solved problems found: {len(all_questions)}")

    # Safeguard: Fail loudly if cookies expired
    if len(all_questions) == 0:
        print("ERROR: 0 problems found. Your LEETCODE_SESSION cookie has likely expired.")
        sys.exit(1)

    # 2. Check existing files to avoid re-fetching code we already have
    existing_files = list(PROBLEMS_DIR.glob("*.*"))
    # Extracts the "0001" from "0001-two-sum.py"
    existing_prefixes = {f.stem.split('-')[0] for f in existing_files} 

    new_problems_count = 0

    # 3. Fetch submissions for missing problems
    for q in all_questions:
        frontend_id = str(q["frontendId"]).zfill(4)
        title = q["title"]
        slug = q["titleSlug"]
        difficulty = q["difficulty"]

        # Skip if we already downloaded this problem
        if frontend_id in existing_prefixes:
            continue

        print(f"Fetching code for {frontend_id}: {title}...")
        
        try:
            # Get the list of recent submissions (limit 20 in case of multiple recent WAs)
            sub_data = graphql("submissionList", SUBMISSIONS_QUERY, {
                "offset": 0, "limit": 20, "questionSlug": slug
            })
            
            submissions = sub_data.get("questionSubmissionList", {}).get("submissions", [])
            
            # Find the most recent "Accepted" submission
            ac_submission = next((s for s in submissions if s["statusDisplay"] == "Accepted"), None)
            
            if not ac_submission:
                print(f"  Warning: No Accepted submission found in last 20 attempts for {slug}.")
                continue

            sub_id = int(ac_submission["id"])
            lang = ac_submission["lang"]
            ext = EXTENSIONS.get(lang, "txt")

            # Get the actual code for that specific submission
            details_data = graphql("submissionDetails", SUBMISSION_DETAILS_QUERY, {
                "submissionId": sub_id
            })
            
            # Safely extract code, handling potential null returns from LeetCode API
            details = details_data.get("submissionDetails")
            if not details or not details.get("code"):
                print(f"  Warning: Code payload was empty for {slug}. Skipping.")
                continue
                
            code = details["code"]
            file_name = f"{frontend_id}-{slug}.{ext}"
            file_path = PROBLEMS_DIR / file_name

            # Format the header based on the language's comment syntax
            if ext in ["py", "rb", "sh"]:
                header = f"# LeetCode Problem {frontend_id}: {title}\n# Difficulty: {difficulty}\n# Link: https://leetcode.com/problems/{slug}/\n# Language: {lang}\n\n"
            elif ext == "sql":
                header = f"-- LeetCode Problem {frontend_id}: {title}\n-- Difficulty: {difficulty}\n-- Link: https://leetcode.com/problems/{slug}/\n-- Language: {lang}\n\n"
            else:
                header = f"// LeetCode Problem {frontend_id}: {title}\n// Difficulty: {difficulty}\n// Link: https://leetcode.com/problems/{slug}/\n// Language: {lang}\n\n"

            # Save the file
            file_path.write_text(header + code, encoding="utf-8")
            new_problems_count += 1
            
            # Sleep briefly to avoid LeetCode rate limits (Error 429)
            time.sleep(1.5)
            
        except Exception as e:
            print(f"  Failed to fetch code for {slug}: {e}")

    print(f"Synchronization complete. Added {new_problems_count} new files.")

if __name__ == "__main__":
    main()
