// LeetCode Problem 1903: Largest Odd Number in String
// Difficulty: Easy
// Link: https://leetcode.com/problems/largest-odd-number-in-string/
// Language: cpp

class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = num.size()-1; i >= 0; i--){
            if(num[i] % 2){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};