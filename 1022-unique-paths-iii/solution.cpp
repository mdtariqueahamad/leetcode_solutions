class Solution {

    int count, n, m;

    void solve(vector<vector<int>> &grid, int rem, int i = 0, int j = 0) {

        if(i >= n || j >= m || i < 0 || j < 0) return;
        if(2 == grid[i][j]) {
            count += rem == 0;
            return;
        } else if(-1 == grid[i][j] || 3 == grid[i][j]) {
            return;
        }

        int temp = grid[i][j]; grid[i][j] = 3;
        solve(grid, rem-1, i, j+1);
        solve(grid, rem-1, i+1, j);
        solve(grid, rem-1, i, j-1);
        solve(grid, rem-1, i-1, j);
        if(1 != temp) grid[i][j] = 0;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        count = 0, n = grid.size(), m = grid[0].size();

        int rem = n*m-1;

        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(-1 == grid[i][j]) rem--;

        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(1 == grid[i][j])
                solve(grid, rem, i, j);

        return count;
    }
};
