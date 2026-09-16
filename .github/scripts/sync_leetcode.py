import os
import re
import sys
import time
from datetime import datetime, timezone
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
query userProgressQuestionList($filters: UserProgressQuestionListInput) {
    userProgressQuestionList(filters: $filters) {
        totalNum
        questions {
            frontendId
            title
            titleSlug
            difficulty
        }
    }
}
"""

SUBMISSIONS_QUERY = """
query submissionList($offset: Int!, $limit: Int!, $questionSlug: String!) {
    questionSubmissionList(offset: $offset, limit: $limit, questionSlug: $questionSlug) {
        lastKey
        hasNext
        submissions {
            id
            statusDisplay
            lang
            timestamp
        }
    }
}
"""

SUBMISSION_DETAILS_QUERY = """
query submissionDetails($submissionId: Int!) {
    submissionDetails(submissionId: $submissionId) {
        code
        statusDisplay
    }
}
"""

def main():
    print("Starting LeetCode Sync...")
    
    data = graphql("userProgressQuestionList", SOLVED_QUERY, {"filters": {"questionStatus": "SOLVED", "limit": 1000}})
    result = data.get("userProgressQuestionList")
    if not result:
        raise RuntimeError("Failed to fetch solved problems. Check your cookies.")
    
    questions = result.get("questions", [])
    print(f"Found {len(questions)} solved problems.")

    for q in questions:
        slug = q["titleSlug"]
        frontend_id = str(q["frontendId"]).zfill(4)
        
        sub_data = graphql("submissionList", SUBMISSIONS_QUERY, {"offset": 0, "limit": 10, "questionSlug": slug})
        sub_list = sub_data.get("questionSubmissionList", {}).get("submissions", [])
        
        accepted = [s for s in sub_list if s.get("statusDisplay") == "Accepted"]
        if not accepted:
            continue
            
        latest = accepted[0]
        sub_id = latest["id"]
        
        details = graphql("submissionDetails", SUBMISSION_DETAILS_QUERY, {"submissionId": int(sub_id)})
        code_data = details.get("submissionDetails")
        
        if not code_data or not code_data.get("code"):
            continue

        folder = REPO_ROOT / f"{frontend_id}-{slug}"
        folder.mkdir(parents=True, exist_ok=True)
        
        file_path = folder / f"solution.py"
        if file_path.exists():
            continue
            
        file_path.write_text(code_data["code"], encoding="utf-8")
        print(f"Synced: {frontend_id}-{slug}")

    print("Sync complete.")

if __name__ == "__main__":
    main()
