// LeetCode Problem 0168: Excel Sheet Column Title
// Difficulty: Easy
// Link: https://leetcode.com/problems/excel-sheet-column-title/
// Language: cpp

class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while(n){
            n--;
            s += (n % 26) + 65;
            n /= 26;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};