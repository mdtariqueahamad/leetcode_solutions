// LeetCode Problem 0169: Majority Element
// Difficulty: Easy
// Link: https://leetcode.com/problems/majority-element/
// Language: cpp

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};