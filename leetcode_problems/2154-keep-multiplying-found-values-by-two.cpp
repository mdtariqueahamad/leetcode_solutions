// LeetCode Problem 2154: Keep Multiplying Found Values by Two
// Difficulty: Easy
// Link: https://leetcode.com/problems/keep-multiplying-found-values-by-two/
// Language: cpp

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        for(auto x : nums){
            if(x == original)
            original *= 2;
        }
        return original;
    }
};