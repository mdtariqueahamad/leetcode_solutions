// LeetCode Problem 0003: Longest Substring Without Repeating Characters
// Difficulty: Medium
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Language: cpp

class Solution {
public:
    int lengthOfLongestSubstring(string s){
        if(!s.size()) return 0;
        int mx = 0;
        unordered_map<char,int> mpp;
        int i = 0, j = 0;
        for( ;s[j]; j++){
            if(mpp[s[j]]){
                i = max(i,mpp[s[j]]);
            }
            mpp[s[j]] = j + 1;
            mx = max(mx, j-i+1);
        }
        return mx;
    }
};