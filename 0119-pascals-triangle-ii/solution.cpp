class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<vector<int>> res(numRows+1);
        res[0] = {1};
        int i = 1;
        for(; i <= numRows; i++){
            res[i].push_back(1);
            for(int j = 1; j < i; j++){
                res[i].push_back(res[i-1][j-1]+res[i-1][j]);
            }
            res[i].push_back(1);
        }
        return res[numRows];
    }
};
