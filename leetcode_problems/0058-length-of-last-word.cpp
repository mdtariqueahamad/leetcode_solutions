// LeetCode Problem 0058: Length of Last Word
// Difficulty: Easy
// Link: https://leetcode.com/problems/length-of-last-word/
// Language: cpp

class Solution {
public:
    int lengthOfLastWord(string s) {
        char *ptr = &s[s.size()-1];
        while(*ptr == ' ' && ptr >= &s[0]) ptr--;
        int count = 0;
        while(ptr >= &s[0]){
            if(*ptr == ' ') return count;
            ptr--;
            count++;
        }
        return count;
    }
};