// LeetCode Problem 0014: Longest Common Prefix
// Difficulty: Easy
// Link: https://leetcode.com/problems/longest-common-prefix/
// Language: cpp

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;
        int mn = INT_MAX;
        for(int i = 0; i < strs.size(); i++)
        mn = min(mn,(int)strs[i].size());
        for(int j = 0; j < mn;j++){
            for(int i = 1; i < strs.size(); i++){
            if(strs[i-1][j] != strs[i][j]) return s;
            }
            s += strs[0][j];
        }
        return s;
    }
};