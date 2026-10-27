class Solution {

    int n, m, k;

    long long dfs(vector<vector<int>> &grid, int i, int j) {

        if(i >= n || i < 0 || j < 0 || j >= m) return 0;

        if(0 == grid[i][j]) return 0;

        int sum = grid[i][j];
        grid[i][j] = 0;

        int left = dfs(grid, i, j+1) % k;
        int right = dfs(grid, i, j-1) % k;
        int up = dfs(grid, i-1, j) % k;
        int down = dfs(grid, i+1, j) % k;

        return (sum + left + right + up + down) % k;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        
        n = grid.size(), m = grid[0].size(), this->k = k;

        long long ans = 0;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j])
                    ans += !((dfs(grid, i, j)) % (long long)k);

        return ans;
    }
};