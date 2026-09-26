// LeetCode Problem 0387: First Unique Character in a String
// Difficulty: Easy
// Link: https://leetcode.com/problems/first-unique-character-in-a-string/
// Language: cpp

class Solution {
public:
    int firstUniqChar(string s) {
       int arr[26] = {0};
       for(char c : s)
       arr[c - 'a']++;

       for(int i = 0; i < s.size(); i++)
       if(arr[s[i] - 'a'] == 1) return i;

       return -1;
    }
};