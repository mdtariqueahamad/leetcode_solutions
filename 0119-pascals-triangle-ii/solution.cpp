class Solution {
public:
    vector<int> getRow(int n) {

        vector<vector<int>> PT(n+1);

        for(int i = 0; i <= n; i++) {
            PT[i].resize(i+1);

            PT[i][0] = PT[i][i] = 1;

            for(int j = 1; j < i; j++) {
                PT[i][j] = (PT[i-1][j] + PT[i-1][j-1]);
            }
        }

        return PT.back();
    }
};
