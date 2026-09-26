// LeetCode Problem 0172: Factorial Trailing Zeroes
// Difficulty: Medium
// Link: https://leetcode.com/problems/factorial-trailing-zeroes/
// Language: cpp

class Solution {
public:
    int trailingZeroes(int n) {
        int zero = 0;
        for(int i = 5; n / i ; i *= 5)
        zero += n / i;
        return zero;
    }
};