// LeetCode Problem 1979: Find Greatest Common Divisor of Array
// Difficulty: Easy
// Link: https://leetcode.com/problems/find-greatest-common-divisor-of-array/
// Language: cpp

class Solution {
public:
    int gcd(int num1, int num2){
    if(!(num2 % num1)) return num1;
    return gcd(num2 % num1, num1);
    }
    int findGCD(vector<int>& nums) {
        int mx = nums[0], mn = nums[0];
        for(int x : nums){
            mx = max(mx, x);
            mn = min(mn, x);
        }
        return gcd(mx, mn);
    }
};