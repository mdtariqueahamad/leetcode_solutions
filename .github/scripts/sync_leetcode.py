import os
import re
import subprocess
import sys
import time
from datetime import datetime, timezone
from pathlib import Path

import requests


# ============================================================
# CONFIG
# ============================================================

GRAPHQL_URL = "https://leetcode.com/graphql/"

SESSION = os.environ.get(SECRET_2)
CSRF_TOKEN = os.environ.get(SECRET_3)

if not SESSION:
    print("ERROR: LEETCODE_SESSION secret is missing.")
    sys.exit(1)

if not CSRF_TOKEN:
    print("ERROR: LEETCODE_CSRF_TOKEN secret is missing.")
    sys.exit(1)

# Repository root:
# .github/scripts/sync_leetcode.py
#        ↑
# parents[0] = scripts
# parents[1] = .github
# parents[2] = repository root
REPO_ROOT = Path(__file__).resolve().parents[2]

REQUEST_DELAY = 1.0


# ============================================================
# HTTP SESSION
# ============================================================

http = requests.Session()

http.cookies.set(
    SECRET_2,
    SESSION,
    domain=".leetcode.com"
)

http.cookies.set(
    SECRET_3,
    CSRF_TOKEN,
    domain=".leetcode.com"
)

HEADERS = {
    "Content-Type": "application/json",
    "Origin": "https://leetcode.com",
    "Referer": "https://leetcode.com/",
    "X-CSRFToken": CSRF_TOKEN,
    "User-Agent": (
        "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
        "AppleWebKit/537.36 "
        "(KHTML, like Gecko) "
        "Chrome/140.0.0.0 Safari/537.36"
    ),
}


# ============================================================
# GRAPHQL
# ============================================================

def graphql(operation_name, query, variables=None):

    payload = {
        "operationName": operation_name,
        "query": query,
        "variables": variables or {},
    }

    try:
        response = http.post(
            GRAPHQL_URL,
            headers=HEADERS,
            json=payload,
            timeout=30,
        )

    except requests.RequestException as e:
        raise RuntimeError(
            f"Network error: {e}"
        )

    if response.status_code != 200:
        raise RuntimeError(
            f"LeetCode HTTP {response.status_code}: "
            f"{response.text[:500]}"
        )

    try:
        body = response.json()

    except ValueError:
        raise RuntimeError(
            "LeetCode returned invalid JSON."
        )

    if body.get("errors"):
        raise RuntimeError(
            f"GraphQL error: {body['errors']}"
        )

    return body.get("data", {})


# ============================================================
# GET SOLVED PROBLEMS
# ============================================================

SOLVED_PROBLEMS_QUERY = """
query userProgressQuestionList(
    $filters: UserProgressQuestionListInput
) {
    userProgressQuestionList(filters: $filters) {
        totalNum

        questions {
            frontendId
            title
            titleSlug
            difficulty
            lastSubmittedAt
        }
    }
}
"""


def get_solved_problems():

    print("Fetching solved problems...")

    data = graphql(
        "userProgressQuestionList",
        SOLVED_PROBLEMS_QUERY,
        {
            "filters": {
                "questionStatus": "SOLVED",
                "skip": 0,
                "limit": 1000,
            }
        },
    )

    result = data.get(
        "userProgressQuestionList"
    )

    if not result:
        raise RuntimeError(
            "LeetCode did not return solved-problem data."
        )

    questions = result.get("questions")

    if not isinstance(questions, list):
        raise RuntimeError(
            "Unexpected solved-problem response."
        )

    print(
        f"Found {len(questions)} solved problems."
    )

    return questions


# ============================================================
# GET ALL SUBMISSIONS FOR A PROBLEM
#
# Current LeetCode GraphQL uses questionSubmissionList.
# This avoids the old submissionList assumption that causes
# the error you were getting from joshcai/leetcode-sync.
# ============================================================

SUBMISSIONS_QUERY = """
query submissionList(
    $offset: Int!,
    $limit: Int!,
    $lastKey: String,
    $questionSlug: String!
) {
    questionSubmissionList(
        offset: $offset,
        limit: $limit,
        lastKey: $lastKey,
        questionSlug: $questionSlug
    ) {
        lastKey
        hasNext

        submissions {
            id
            statusDisplay
            lang
            timestamp
            url
        }
    }
}
"""


def get_submissions(slug):

    submissions = []

    offset = 0
    last_key = None

    while True:

        data = graphql(
            "submissionList",
            SUBMISSIONS_QUERY,
            {
                "offset": offset,
                "limit": 20,
                "lastKey": last_key,
                "questionSlug": slug,
            },
        )

        result = data.get(
            "questionSubmissionList"
        )

        if not result:
            print(
                f"  No submission data for {slug}"
            )
            break

        current = result.get(
            "submissions"
        )

        # Critical protection against:
        #
        # TypeError:
        # response.data.data.submissionList.submissions
        # is not iterable
        #
        if not isinstance(current, list):

            print(
                f"  WARNING: submissions is not a list "
                f"for {slug}. Skipping."
            )

            break

        submissions.extend(current)

        if not result.get("hasNext"):
            break

        last_key = result.get("lastKey")

        if not current:
            break

        offset += len(current)

        time.sleep(REQUEST_DELAY)

    return submissions


# ============================================================
# SUBMISSION DETAILS
# ============================================================

SUBMISSION_DETAILS_QUERY = """
query submissionDetails(
    $submissionId: Int!
) {
    submissionDetails(
        submissionId: $submissionId
    ) {
        code
        timestamp
        statusCode
        statusDisplay
        runtime
        memory

        lang {
            name
            verboseName
        }

        question {
            title
            titleSlug
            questionFrontendId
        }
    }
}
"""


def get_submission_details(submission_id):

    data = graphql(
        "submissionDetails",
        SUBMISSION_DETAILS_QUERY,
        {
            "submissionId": int(submission_id)
        },
    )

    return data.get(
        "submissionDetails"
    )


# ============================================================
# LANGUAGE → EXTENSION
# ============================================================

LANGUAGE_EXTENSIONS = {
    "c": ".c",
    "cpp": ".cpp",
    "c++": ".cpp",
    "java": ".java",
    "python": ".py",
    "python3": ".py",
    "pythondata": ".py",
    "pandas": ".py",
    "javascript": ".js",
    "typescript": ".ts",
    "csharp": ".cs",
    "c#": ".cs",
    "go": ".go",
    "rust": ".rs",
    "kotlin": ".kt",
    "swift": ".swift",
    "ruby": ".rb",
    "php": ".php",
    "scala": ".scala",
    "dart": ".dart",
    "mysql": ".sql",
    "mssql": ".sql",
    "postgresql": ".sql",
}


def extension_for_language(language):

    language = (
        language or "unknown"
    ).lower().strip()

    return LANGUAGE_EXTENSIONS.get(
        language,
        ".txt"
    )


# ============================================================
# SAFE FILE NAME
# ============================================================

def safe_name(value):

    value = value.strip()

    value = re.sub(
        r"[^a-zA-Z0-9._-]+",
        "-",
        value
    )

    return value.strip("-")


# ============================================================
# FIND SUBMISSION ID IN REPOSITORY
# ============================================================

def submission_already_synced(submission_id):

    marker = str(submission_id)

    for path in REPO_ROOT.rglob("*"):

        if not path.is_file():
            continue

        if ".git" in path.parts:
            continue

        if marker in path.name:
            return True

    return False


# ============================================================
# GIT
# ============================================================

def git(*args):

    result = subprocess.run(
        ["git", *args],
        cwd=REPO_ROOT,
        text=True,
        capture_output=True,
    )

    if result.returncode != 0:

        print(
            f"GIT ERROR: git {' '.join(args)}"
        )

        print(result.stdout)
        print(result.stderr)

        raise RuntimeError(
            "Git command failed."
        )

    return result.stdout.strip()


def git_commit_for_submission(
    file_path,
    submission_timestamp,
    submission_id,
):

    dt = datetime.fromtimestamp(
        int(submission_timestamp),
        tz=timezone.utc
    )

    git_date = dt.strftime(
        "%Y-%m-%dT%H:%M:%S%z"
    )

    relative_path = file_path.relative_to(
        REPO_ROOT
    )

    git(
        "add",
        str(relative_path)
    )

    commit_message = (
        f"Add LeetCode submission "
        f"{submission_id}"
    )

    env = os.environ.copy()

    # Author and committer dates are both important.
    env["GIT_AUTHOR_DATE"] = git_date
    env["GIT_COMMITTER_DATE"] = git_date

    result = subprocess.run(
        [
            "git",
            "commit",
            "-m",
            commit_message,
        ],
        cwd=REPO_ROOT,
        text=True,
        capture_output=True,
        env=env,
    )

    if result.returncode != 0:

        print(result.stdout)
        print(result.stderr)

        raise RuntimeError(
            "Git commit failed."
        )

    print(
        f"    Commit created for "
        f"{dt.isoformat()}"
    )


# ============================================================
# CREATE FILE
# ============================================================

def create_solution(
    problem,
    submission,
    details,
):

    submission_id = submission["id"]

    frontend_id = str(
        problem["frontendId"]
    ).zfill(4)

    slug = problem["titleSlug"]

    language = (
        submission.get("lang")
        or details.get("lang", {}).get("name")
        or "unknown"
    )

    timestamp = int(
        submission["timestamp"]
    )

    dt = datetime.fromtimestamp(
        timestamp,
        tz=timezone.utc
    )

    date_string = dt.strftime(
        "%Y-%m-%d"
    )

    extension = extension_for_language(
        language
    )

    folder_name = (
        f"{frontend_id}-"
        f"{safe_name(slug)}"
    )

    folder = (
        REPO_ROOT / folder_name
    )

    folder.mkdir(
        parents=True,
        exist_ok=True
    )

    # Submission ID makes every accepted attempt unique.
    filename = (
        f"{date_string}_"
        f"{submission_id}"
        f"{extension}"
    )

    file_path = folder / filename

    if file_path.exists():
        return None

    code = details.get("code")

    if not code:
        print(
            f"    WARNING: No source code "
            f"returned for {submission_id}"
        )

        return None

    file_path.write_text(
        code,
        encoding="utf-8"
    )

    print(
        f"    Created: "
        f"{file_path.relative_to(REPO_ROOT)}"
    )

    return file_path


# ============================================================
# MAIN
# ============================================================

def main():

    print("=" * 65)
    print("        LEETCODE → GITHUB CUSTOM SYNC")
    print("=" * 65)

    problems = get_solved_problems()

    total_accepted = 0
    new_submissions = 0

    # Oldest → newest problems isn't important.
    # We process each problem's submissions chronologically.
    for index, problem in enumerate(
        problems,
        start=1
    ):

        slug = problem["titleSlug"]
        title = problem["title"]

        print(
            f"\n[{index}/{len(problems)}] "
            f"{problem['frontendId']}. {title}"
        )

        try:

            submissions = get_submissions(
                slug
            )

        except Exception as e:

            print(
                f"  ERROR: {e}"
            )

            continue

        accepted = [
            s
            for s in submissions
            if s.get("statusDisplay")
            == "Accepted"
        ]

        accepted.sort(
            key=lambda s: int(
                s["timestamp"]
            )
        )

        print(
            f"  Accepted submissions: "
            f"{len(accepted)}"
        )

        total_accepted += len(
            accepted
        )

        for submission in accepted:

            submission_id = submission["id"]

            # Existing submission?
            if submission_already_synced(
                submission_id
            ):

                print(
                    f"    Already synced: "
                    f"{submission_id}"
                )

                continue

            print(
                f"    New accepted submission: "
                f"{submission_id}"
            )

            try:

                time.sleep(
                    REQUEST_DELAY
                )

                details = (
                    get_submission_details(
                        submission_id
                    )
                )

                if not details:

                    print(
                        f"    Could not retrieve "
                        f"submission details."
                    )

                    continue

                # Extra safety check.
                if (
                    details.get(
                        "statusDisplay"
                    )
                    != "Accepted"
                ):

                    print(
                        f"    Submission is no longer "
                        f"reported as Accepted."
                    )

                    continue

                file_path = create_solution(
                    problem,
                    submission,
                    details,
                )

                if not file_path:
                    continue

                # Commit using the ACTUAL LeetCode
                # submission timestamp.
                git_commit_for_submission(
                    file_path,
                    submission["timestamp"],
                    submission_id,
                )

                new_submissions += 1

            except Exception as e:

                print(
                    f"    ERROR processing "
                    f"{submission_id}: {e}"
                )

    print("\n" + "=" * 65)
    print("SYNC FINISHED")
    print("=" * 65)

    print(
        f"Accepted submissions found: "
        f"{total_accepted}"
    )

    print(
        f"New submissions synced: "
        f"{new_submissions}"
    )

    # Push only if something changed.
    if new_submissions > 0:

        print("\nPushing commits to GitHub...")

        git(
            "push",
            "origin",
            "main"
        )

        print("Push successful.")

    else:

        print(
            "\nNothing new. "
            "No GitHub commit was created."
        )


if __name__ == "__main__":
    main()