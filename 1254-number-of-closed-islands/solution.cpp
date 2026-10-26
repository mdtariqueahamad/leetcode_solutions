class Solution {
    int m, n;

    bool dfs(vector<vector<int>> &grid, int i, int j) {

        if(i >= n || i < 0 || j < 0 || j >= m) return false;

        if(1 == grid[i][j]) return true;

        grid[i][j] = 1;

        bool left = dfs(grid, i, j+1);
        bool right = dfs(grid, i, j-1);
        bool up = dfs(grid, i-1, j);
        bool down = dfs(grid, i+1, j);

        return left && right && up && down;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {

        n = grid.size(), m = grid[0].size();

        int count = 0;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!grid[i][j])
                    count += dfs(grid, i, j);

        return count;
    }
};