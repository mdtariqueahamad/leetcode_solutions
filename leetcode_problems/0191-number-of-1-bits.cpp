// LeetCode Problem 0191: Number of 1 Bits
// Difficulty: Easy
// Link: https://leetcode.com/problems/number-of-1-bits/
// Language: cpp

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n){
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
};