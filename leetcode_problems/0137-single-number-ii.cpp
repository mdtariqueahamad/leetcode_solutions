// LeetCode Problem 0137: Single Number II
// Difficulty: Medium
// Link: https://leetcode.com/problems/single-number-ii/
// Language: cpp

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int x : nums)
        mp[x]++;

        for(auto x : mp)
            if(x.second == 1) return x.first;

        return -1;
    }
};