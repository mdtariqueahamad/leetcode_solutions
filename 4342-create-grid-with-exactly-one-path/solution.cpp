class Solution {
public:
    vector<string> createGrid(int m, int n) {

    vector<string> ans(m, string(n, '#'));

        for(int i = 0; i < n; i++) {
            ans[0][i] = '.';
        }

        if(n < 1) return ans;

        for(int i = 1; i < m; i++) {
            ans[i][n-1] = '.';
        }

        return ans;
    }
};
