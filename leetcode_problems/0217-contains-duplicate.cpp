// LeetCode Problem 0217: Contains Duplicate
// Difficulty: Easy
// Link: https://leetcode.com/problems/contains-duplicate/
// Language: cpp

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i = 1; i < nums.size(); i++)
        if(nums[i-1] == nums[i]) return true;

        return false;
    }
};