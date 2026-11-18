class Solution {
    const static int MOD = 1e9+7;
public:
    int numTilings(int n) {
        
        if(n < 3) return n;
        vector<int> dp(n+1);

        dp[1] = 1, dp[2] = 2, dp[3] = 5;

        for(int i = 4; i <= n; i++)
            dp[i] = (dp[i-3] % MOD + 2LL * dp[i-1] % MOD ) % MOD;

        return dp[n];
    }
};
