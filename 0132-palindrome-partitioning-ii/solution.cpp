class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for(int i = 0; i < n; i++)
            pal[i][i] = true;

        for(int len = 2; len <= n; len++)
            for(int i = 0; i + len <= n; i++) {

                int j = i + len - 1;

                if(s[i] == s[j]) {
                    if(len == 2)
                        pal[i][j] = true;
                    else
                        pal[i][j] = pal[i+1][j-1];
                }
            }

        vector<int> dp(n);

        for(int i = 0; i < n; i++) {

            if(pal[0][i]) dp[i] = 0;
            else {
                dp[i] = INT_MAX;

                for(int idx = 0; idx < i; idx++) {
                    if(pal[idx+1][i]) {
                        dp[i] = min(1 + dp[idx], dp[i]);
                    }
                }
            }
        }

        return dp.back();
    }
};
