class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {

        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {

            if (i < n)
                dp[i] = min(dp[i], costs[i] + 1 + dp[i + 1]);

            if (i + 1 < n)
                dp[i] = min(dp[i], costs[i + 1] + 4 + dp[i + 2]);

            if (i + 2 < n)
                dp[i] = min(dp[i], costs[i + 2] + 9 + dp[i + 3]);
        }

        return dp[0];
    }
};
