import os
import sys
import time
import requests
from pathlib import Path

GRAPHQL_URL = "https://leetcode.com/graphql/"

SESSION = os.environ.get("LEETCODE_SESSION", "").strip()
CSRF_TOKEN = os.environ.get("LEETCODE_CSRF_TOKEN", "").strip()

if not SESSION or not CSRF_TOKEN:
    print("ERROR: LeetCode session cookies are missing. Check your GitHub Secrets.")
    sys.exit(1)

# Base directory is now the root of the repository
REPO_ROOT = Path(__file__).resolve().parents[2]

http = requests.Session()
http.cookies.set("LEETCODE_SESSION", SESSION, domain=".leetcode.com")
http.cookies.set("csrftoken", CSRF_TOKEN, domain=".leetcode.com")

HEADERS = {
    "Content-Type": "application/json",
    "Origin": "https://leetcode.com",
    "Referer": "https://leetcode.com/",
    "X-CSRFToken": CSRF_TOKEN,
    "User-Agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36", 
}

def graphql(operation_name, query, variables=None):
    payload = {"operationName": operation_name, "query": query, "variables": variables or {}}
    response = http.post(GRAPHQL_URL, headers=HEADERS, json=payload, timeout=30)
    
    if response.status_code != 200:
        print(f"\nServer Response Body: {response.text}\n")
        raise RuntimeError(f"LeetCode HTTP Error {response.status_code}")
        
    body = response.json()
    if body.get("errors"):
        raise RuntimeError(f"GraphQL error: {body['errors']}")
        
    return body.get("data", {})

SOLVED_QUERY = """
query problemsetQuestionList(DOLLARcategorySlug: String, DOLLARlimit: Int, DOLLARskip: Int, DOLLARfilters: QuestionListFilterInput) {
    problemsetQuestionList: questionList(
        categorySlug: DOLLARcategorySlug
        limit: DOLLARlimit
        skip: DOLLARskip
        filters: DOLLARfilters
    ) {
        total: totalNum
        questions: data {
            frontendId: questionFrontendId
            title
            titleSlug
            difficulty
        }
    }
}
""".replace("DOLLAR", "$")

SUBMISSIONS_QUERY = """
query submissionList(DOLLARoffset: Int!, DOLLARlimit: Int!, DOLLARquestionSlug: String!) {
    questionSubmissionList(offset: DOLLARoffset, limit: DOLLARlimit, questionSlug: DOLLARquestionSlug) {
        submissions {
            id
            statusDisplay
            lang
        }
    }
}
""".replace("DOLLAR", "$")

SUBMISSION_DETAILS_QUERY = """
query submissionDetails(DOLLARsubmissionId: Int!) {
    submissionDetails(submissionId: DOLLARsubmissionId) {
        code
    }
}
""".replace("DOLLAR", "$")

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

    if len(all_questions) == 0:
        print("ERROR: 0 problems found. Your LEETCODE_SESSION cookie has likely expired.")
        sys.exit(1)

    new_problems_count = 0

    for q in all_questions:
        frontendId_raw = q.get("frontendId")
        if not frontendId_raw:
            continue
            
        frontend_id = str(frontendId_raw).zfill(4)
        title = q["title"]
        slug = q["titleSlug"]
        difficulty = q["difficulty"]

        # 1. Define the folder name (e.g., 0001-two-sum)
        folder_name = f"{frontend_id}-{slug}"
        problem_folder = REPO_ROOT / folder_name

        # Skip if this problem's folder already exists
        if problem_folder.exists():
            continue

        print(f"Fetching code for {frontend_id}: {title}...")
        
        try:
            sub_data = graphql("submissionList", SUBMISSIONS_QUERY, {
                "offset": 0, "limit": 20, "questionSlug": slug
            })
            
            submissions = sub_data.get("questionSubmissionList", {}).get("submissions", [])
            ac_submission = next((s for s in submissions if s["statusDisplay"] == "Accepted"), None)
            
            if not ac_submission:
                print(f"  Warning: No Accepted submission found in last 20 attempts for {slug}.")
                continue

            sub_id = int(ac_submission["id"])
            lang = ac_submission["lang"]
            ext = EXTENSIONS.get(lang, "txt")

            details_data = graphql("submissionDetails", SUBMISSION_DETAILS_QUERY, {
                "submissionId": sub_id
            })
            
            details = details_data.get("submissionDetails")
            if not details or not details.get("code"):
                print(f"  Warning: Code payload was empty for {slug}. Skipping.")
                continue
                
            code = details["code"]
            
            # Create the folder for the problem
            problem_folder.mkdir(parents=True, exist_ok=True)
            
            # 2. Write the solution code file
            file_path = problem_folder / f"solution.{ext}"
            file_path.write_text(code, encoding="utf-8")
            
            # 3. Write the README.md file inside the folder
            readme_path = problem_folder / "README.md"
            readme_content = f"""# {frontend_id}. {title}

**Difficulty:** {difficulty}

**Link:** [https://leetcode.com/problems/{slug}/](https://leetcode.com/problems/{slug}/)

## Solution
**Language:** {lang}
"""
            readme_path.write_text(readme_content, encoding="utf-8")
            
            new_problems_count += 1
            time.sleep(1.5)
            
        except Exception as e:
            print(f"  Failed to fetch code for {slug}: {e}")

    print(f"Synchronization complete. Added {new_problems_count} new problem folders.")

if __name__ == "__main__":
    main()
