// LeetCode Problem 0189: Rotate Array
// Difficulty: Medium
// Link: https://leetcode.com/problems/rotate-array/
// Language: cpp

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        vector <int> temp(k);
        int n = nums.size()-1;
        for(int i = 0; i < k; i++)
            temp[i] = nums[n-i];

        for(int i = n; i >= k; i--)
            nums[i] = nums[i-k];

        for(int i = 0; i < k; i++)
        nums[k-(i+1)] = temp[i];
    }
};