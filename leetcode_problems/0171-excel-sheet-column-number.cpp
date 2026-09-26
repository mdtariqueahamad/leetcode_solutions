// LeetCode Problem 0171: Excel Sheet Column Number
// Difficulty: Easy
// Link: https://leetcode.com/problems/excel-sheet-column-number/
// Language: cpp

class Solution {
public:
    int titleToNumber(string inp) {
        int res = 0;
        for (int i = 0; i < inp.size(); ++i){
            res += (inp[i] - 64) * pow(26, inp.size() - 1 - i);
        }
        return res;
    }
};