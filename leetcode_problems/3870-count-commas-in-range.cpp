// LeetCode Problem 3870: Count Commas in Range
// Difficulty: Easy
// Link: https://leetcode.com/problems/count-commas-in-range/
// Language: cpp

class Solution {
public:
    int countCommas(int n) {
        return max(0, n - 999);
    }
};