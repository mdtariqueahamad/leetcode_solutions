// LeetCode Problem 0153: Find Minimum in Rotated Sorted Array
// Difficulty: Medium
// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Language: cpp

class Solution {
public:
    int findMin(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++)
        if(nums[i-1] > nums[i]) return nums[i];

        return nums[0];
    }
};