// LeetCode Problem 0035: Search Insert Position
// Difficulty: Easy
// Link: https://leetcode.com/problems/search-insert-position/
// Language: cpp

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target) return i;
            else if(nums[i] > target) return i;
        }
        return nums.size();
    }
};