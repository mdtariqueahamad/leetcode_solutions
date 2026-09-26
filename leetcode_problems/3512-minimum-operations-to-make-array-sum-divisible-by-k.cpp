// LeetCode Problem 3512: Minimum Operations to Make Array Sum Divisible by K
// Difficulty: Easy
// Link: https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/
// Language: cpp

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(int x : nums)
        sum += x;

        return sum % k;
    }
};