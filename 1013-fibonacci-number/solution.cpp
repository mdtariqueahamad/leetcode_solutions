class Solution {
public:
    vector<int> dp;
    int helper(int n){
        if(!n || 1 == n) return n;
        if(dp[n] != -1) return dp[n];
        dp[n] = helper(n-1) + helper(n-2);
        return dp[n];
    }
    int fib(int n) {
        dp = vector<int>(n+1, -1);
        return helper(n);
    }
};
