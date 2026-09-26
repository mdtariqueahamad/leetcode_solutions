// LeetCode Problem 0405: Convert a Number to Hexadecimal
// Difficulty: Easy
// Link: https://leetcode.com/problems/convert-a-number-to-hexadecimal/
// Language: cpp

class Solution {
public:
    string toHex(unsigned int num) {
        string res;
        if(!num) return "0";
        while(num){
            int x = num % 16;
            char c = x < 10 ? '0' + x : 'a' + x - 10;
            res = c + res;
            num /= 16;
        }
        return res;
    }
};