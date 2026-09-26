// LeetCode Problem 0231: Power of Two
// Difficulty: Easy
// Link: https://leetcode.com/problems/power-of-two/
// Language: cpp

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(!n) return false;
        if(n == INT_MIN) return false;
        return !(n & n-1);
    }
};