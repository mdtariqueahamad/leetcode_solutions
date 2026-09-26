// LeetCode Problem 0283: Move Zeroes
// Difficulty: Easy
// Link: https://leetcode.com/problems/move-zeroes/
// Language: cpp

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = 0;
        int m = 0;
        for(int i = 0; i<nums.size(); i++){
            if(!nums[i]) n++;
            else{
                nums[m]=nums[i];
                m++;
            }
        }
        for(int i = n; i > 0; i--){
            nums[nums.size()-i] = 0;
        }
    }
};