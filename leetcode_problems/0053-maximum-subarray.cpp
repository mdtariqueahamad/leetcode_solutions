// LeetCode Problem 0053: Maximum Subarray
// Difficulty: Medium
// Link: https://leetcode.com/problems/maximum-subarray/
// Language: cpp

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, max = nums[0];
        for(int i : nums){
            sum += i;
            if(sum > max) max = sum;
            if(sum < 0) sum = 0;
        }
        return max;
    }
};