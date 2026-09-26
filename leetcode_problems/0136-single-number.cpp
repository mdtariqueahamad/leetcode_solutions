// LeetCode Problem 0136: Single Number
// Difficulty: Easy
// Link: https://leetcode.com/problems/single-number/
// Language: cpp

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = 0;
        for(int i: nums){
            n ^= i;
        }
        return n;
    }
};