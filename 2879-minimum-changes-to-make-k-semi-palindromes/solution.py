def segmentCost(s: str, l: int, m: int, factors: list) -> int:
    best = m
    for d in factors[m]:
        groups = m // d  # Each group contains groups characters
        changes = 0
        for offset in range(d):
            for t in range(
                groups // 2
            ):  # Pair characters from opposite ends of the group
                if (
                    s[l + offset + t * d]
                    != s[l + offset + (groups - 1 - t) * d]
                ):
                    changes += 1
        best = min(best, changes)
    return best


class Solution:
    def minimumChanges(self, s: str, k: int) -> int:
        n = len(s)
        factors = [[] for _ in range(n + 1)]
        # Precompute the proper divisors of each number
        for d in range(1, n // 2 + 1):
            for m in range(d * 2, n + 1, d):
                factors[m].append(d)
        cost = [[0] * n for _ in range(n)]
        for l in range(n - 1):
            for r in range(
                l + 1, n
            ):  # Each substring must have length at least 2
                cost[l][r] = segmentCost(s, l, r - l + 1, factors)

        prev = [cost[start][n - 1] for start in range(n)]  # The case seg = 1
        for seg in range(
            2, k + 1
        ):  # Increase the number of segments from 2 to k
            cur = [n] * n
            limit = n - 1 - 2 * (seg - 1)
            for start in range(
                n - 2 * seg + 1
            ):  # Leave at least 2*seg characters
                cur[start] = min(
                    cost[start][e] + prev[e + 1]
                    for e in range(start + 1, limit + 1)
                )
            prev = cur
        return prev[0]
