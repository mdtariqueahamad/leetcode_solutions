class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        map<vector<int>, int> mpp;

        for(auto x: grid)
            mpp[x]++;
        
        int ans = 0;

        for(int j = 0; j < grid.size(); j++) {

            vector<int> col;

            for(int i = 0; i < grid.size(); i++)
                col.push_back(grid[i][j]);

            if(mpp.find(col) != mpp.end())
                ans += mpp[col];
        }

        return ans;
    }
};