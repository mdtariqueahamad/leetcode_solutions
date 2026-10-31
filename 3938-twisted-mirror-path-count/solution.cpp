class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n;

    vector<vector<vector<int>>> memo;
    int resolve(vector<vector<int>>& grid, int i, int j, int dir) {
        if (i >= m || j >= n)
            return -1;

        if (grid[i][j] == 0)
            return i * n + j;

        int& res = memo[i][j][dir];

        if (res != -2)
            return res;

        if (dir == 0) {
            res = resolve(grid, i + 1, j, 1);
        } else {
            res = resolve(grid, i, j + 1, 0);
        }

        return res;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memo.assign(m, vector<vector<int>>(
            n, vector<int>(2, -2)
        ));

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 || dp[i][j] == 0)
                    continue;

                int dest = resolve(grid, i, j + 1, 0);

                if (dest != -1) {
                    int x = dest / n;
                    int y = dest % n;

                    dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                }

                dest = resolve(grid, i + 1, j, 1);

                if (dest != -1) {
                    int x = dest / n;
                    int y = dest % n;

                    dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
