// LeetCode Problem 0268: Missing Number
// Difficulty: Easy
// Link: https://leetcode.com/problems/missing-number/
// Language: cpp

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = (nums.size() * (nums.size() + 1)) / 2;
        for(int i = 0; i < nums.size(); i++)
        ans -= nums[i];
        return ans;
    }
};