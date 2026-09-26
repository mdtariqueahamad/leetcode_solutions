// LeetCode Problem 1021: Remove Outermost Parentheses
// Difficulty: Easy
// Link: https://leetcode.com/problems/remove-outermost-parentheses/
// Language: cpp

class Solution {
public:
    string removeOuterParentheses(string s) {
        string s1; int n = 0;
        for(int i = 0; i < s.size(); i++){
                if(s[i] == '(') n++;
            if(n != 1){
                s1 += s[i];
            }
                if(s[i] == ')') n--;
        }
        return s1;
    }
};