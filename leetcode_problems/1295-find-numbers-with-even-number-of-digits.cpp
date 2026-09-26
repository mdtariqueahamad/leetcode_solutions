// LeetCode Problem 1295: Find Numbers with Even Number of Digits
// Difficulty: Easy
// Link: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
// Language: cpp

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int x : nums){
            if(x == 0) count += 1;
            else
            count += !(int((floor(log10(x))) + 1) % 2);
        }
        return count;
    }
};