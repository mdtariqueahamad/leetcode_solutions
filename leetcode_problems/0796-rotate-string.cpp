// LeetCode Problem 0796: Rotate String
// Difficulty: Easy
// Link: https://leetcode.com/problems/rotate-string/
// Language: cpp

class Solution {
public:
    bool rotateString(string s, string goal){
        if(s.size() != goal.size()) return false;
        s += s;
        return s.find(goal) != string::npos;
    }
};