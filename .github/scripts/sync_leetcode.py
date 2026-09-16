import os
import sys
from pathlib import Path
import requests

GRAPHQL_URL = "https://leetcode.com/graphql/"

SESSION = os.environ.get("LEETCODE_SESSION")
CSRF_TOKEN = os.environ.get("LEETCODE_CSRF_TOKEN")

if not SESSION or not CSRF_TOKEN:
    print("ERROR: LeetCode session cookies are missing.")
    sys.exit(1)

REPO_ROOT = Path(__file__).resolve().parents[2]

http = requests.Session()
http.cookies.set("LEETCODE_SESSION", SESSION, domain=".leetcode.com")
http.cookies.set("csrftoken", CSRF_TOKEN, domain=".leetcode.com")

HEADERS = {
    "Content-Type": "application/json",
    "Origin": "https://leetcode.com",
    "Referer": "https://leetcode.com/",
    "X-CSRFToken": CSRF_TOKEN,
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
}

def graphql(operation_name, query, variables=None):
    payload = {"operationName": operation_name, "query": query, "variables": variables or {}}
    response = http.post(GRAPHQL_URL, headers=HEADERS, json=payload, timeout=30)
    
    if response.status_code != 200:
        print(f"DEBUG: Status Code: {response.status_code}")
        print(f"DEBUG: Response Text: {response.text[:500]}")
        raise RuntimeError(f"LeetCode HTTP {response.status_code}")
        
    try:
        body = response.json()
    except ValueError:
        print(f"DEBUG: Response Text (Not JSON): {response.text[:500]}")
        raise RuntimeError("LeetCode returned non-JSON response.")
        
    if body.get("errors"):
        print(f"DEBUG: GraphQL Errors: {body['errors']}")
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
    print("Starting LeetCode Sync...")
    
    data = graphql("problemsetQuestionList", SOLVED_QUERY, {
        "categorySlug": "",
        "skip": 0,
        "limit": 100,
        "filters": {"status": "AC"}
    })
    
    result = data.get("problemsetQuestionList")
    if not result:
        print(f"DEBUG: Full Data Returned: {data}")
        raise RuntimeError("Failed to fetch solved problems from LeetCode API.")
    
    questions = result.get("questions", [])
    print(f"Successfully connected! Found {len(questions)} solved problems.")

if __name__ == "__main__":
    main()
