// LeetCode Problem 0009: Palindrome Number
// Difficulty: Easy
// Link: https://leetcode.com/problems/palindrome-number/
// Language: cpp

class Solution {
public:
    bool isPalindrome(int x) {
        string s1, s = to_string(x);
        s1 = s;
        reverse(s1.begin(), s1.end());
        if(s==s1)
        return true;
        else
        return false;
    }
};