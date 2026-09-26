// LeetCode Problem 0001: Two Sum
// Difficulty: Easy
// Link: https://leetcode.com/problems/two-sum/
// Language: cpp

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

for (int i = 0; i < nums.size(); i++)
    mp[nums[i]] = i;

for (int i = 0; i < nums.size(); i++) {
    int need = target - nums[i];

    if (mp.find(need) != mp.end() && mp[need] != i)
        return {i, mp[need]};
}
        return {};
    }
};