// LeetCode Problem 0279: Perfect Squares
// Difficulty: Medium
// Link: https://leetcode.com/problems/perfect-squares/
// Language: cpp

class Solution {
public:
    int numSquares(int n) {
        vector <int> dp(n+1, 0);
        for(int i = 1; i <= n; i++){
            dp[i] = i;
            for(int j = 1; j*j <= i; j++){
                dp[i] = min(dp[i],(1+dp[i-(j*j)]));
            }
        }
        return dp.back();
    }
};