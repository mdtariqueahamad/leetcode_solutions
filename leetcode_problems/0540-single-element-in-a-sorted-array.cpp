// LeetCode Problem 0540: Single Element in a Sorted Array
// Difficulty: Medium
// Link: https://leetcode.com/problems/single-element-in-a-sorted-array/
// Language: cpp

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = 0;
        for(int x : nums)
        n ^= x;

        return n;
    }
};