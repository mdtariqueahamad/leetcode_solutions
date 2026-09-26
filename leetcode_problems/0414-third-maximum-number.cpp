// LeetCode Problem 0414: Third Maximum Number
// Difficulty: Easy
// Link: https://leetcode.com/problems/third-maximum-number/
// Language: cpp

class Solution {
public:
    int thirdMax(vector<int>& nums){
       sort(nums.begin(), nums.end());
       int n = 2;
       int i = nums.size()-1;
       for(; n && i > 0 ; i--){
        if(nums[i] != nums[i-1]) n--;
       }
        if(n)  return nums[nums.size()-1];
       return nums[i];
    }
};