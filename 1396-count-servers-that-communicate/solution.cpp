class Solution {
    int n, m;

    int solve(int i, int j, vector<vector<int>>& grid) {
        grid[i][j] = 0;
        int cnt = 1;

        for(int k = 0; k < m; k++) {
            if(grid[i][k])
                cnt += solve(i, k, grid);
        }

        for(int k = 0; k < n; k++) {
            if(grid[k][j])
                cnt += solve(k, j, grid);
        }

        return cnt;
    }

public:
    int countServers(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {
                    int cnt = solve(i, j, grid);

                    if(cnt > 1)
                        ans += cnt;
                }
            }
        }

        return ans;
    }
};
