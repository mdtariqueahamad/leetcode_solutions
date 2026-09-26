// LeetCode Problem 3370: Smallest Number With All Set Bits
// Difficulty: Easy
// Link: https://leetcode.com/problems/smallest-number-with-all-set-bits/
// Language: cpp

class Solution {
public:
    int smallestNumber(int n) {
        int m = n * 2;
        int x = 1;
        while(m/=2){
            n |= x;
            x = x << 1;
        }
        return n;
    }
};