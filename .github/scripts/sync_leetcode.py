import os
import sys
import requests
from pathlib import Path

GRAPHQL_URL = "https://leetcode.com/graphql/"

SESSION = os.environ.get("LEETCODE_SESSION")
CSRF_TOKEN = os.environ.get("LEETCODE_CSRF_TOKEN")

if not SESSION or not CSRF_TOKEN:
    print("ERROR: LeetCode session cookies are missing.")
    sys.exit(1)

REPO_ROOT = Path(__file__).resolve().parents[1]
PROBLEMS_DIR = REPO_ROOT / "leetcode_problems"
PROBLEMS_DIR.mkdir(exist_ok=True)

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
        raise RuntimeError(f"LeetCode HTTP {response.status_code}")
    body = response.json()
    if body.get("errors"):
        raise RuntimeError(f"GraphQL error: {body['errors']}")
    return body.get("data", {})

SOLVED_QUERY = """
query problemsetQuestionList($categorySlug: String, $limit: Int, $skip: Int, $filters: QuestionListFilterInput) {
    problemsetQuestionList: questionList(
        categorySlug: $categorySlug
        limit: $limit
        skip: $skip
        filters: $filters
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
"""

def main():
    print("Fetching solved problems from LeetCode...")
    skip = 0
    limit = 100
    all_questions = []

    # Fetch with pagination to get all solved problems
    while True:
        data = graphql("problemsetQuestionList", SOLVED_QUERY, {
            "categorySlug": "",
            "skip": skip,
            "limit": limit,
            "filters": {"status": "AC"}
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

    new_files_count = 0
    for q in all_questions:
        frontend_id = q["frontendId"]
        title = q["title"]
        slug = q["titleSlug"]
        difficulty = q["difficulty"]

        file_name = f"{str(frontend_id).zfill(4)}-{slug}.py"
        file_path = PROBLEMS_DIR / file_name

        if not file_path.exists():
            content = f'''# LeetCode Problem {frontend_id}: {title}
# Difficulty: {difficulty}
# Link: https://leetcode.com/problems/{slug}/

def solution():
    pass
'''
            file_path.write_text(content, encoding="utf-8")
            new_files_count += 1

    print(f"Created {new_files_count} new problem files.")

if __name__ == "__main__":
    main()
