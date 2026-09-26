// LeetCode Problem 0029: Divide Two Integers
// Difficulty: Medium
// Link: https://leetcode.com/problems/divide-two-integers/
// Language: cpp

class Solution {
public:
    int divide(int getn, int getx) {
        long long ans = 0;
        int neg = 1;
        if ((getn < 0) ^ (getx < 0)) neg = -1;
        
        long long n = llabs(getn);
        long long x = llabs(getx);

        for(int i = 31; i >=0 ; i--){
            long long m = x << i;
            if(m <= n){
                ans += (1LL << i);
                n -= m;
            }
        }

       if (ans > INT_MAX) {
            return neg == -1 ? INT_MIN : INT_MAX;
        }

        return neg == -1 ? -ans : ans;
    }
};