// LeetCode Problem 0912: Sort an Array
// Difficulty: Medium
// Link: https://leetcode.com/problems/sort-an-array/
// Language: cpp

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};