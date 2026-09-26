// LeetCode Problem 0049: Group Anagrams
// Difficulty: Medium
// Link: https://leetcode.com/problems/group-anagrams/
// Language: cpp

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;

    for (auto& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(s);
    }

    vector<vector<string>> res;
    for (auto& p : groups) {
        res.push_back(p.second);
    }

    return res;
}
};