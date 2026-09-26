// LeetCode Problem 0007: Reverse Integer
// Difficulty: Medium
// Link: https://leetcode.com/problems/reverse-integer/
// Language: cpp

#include <cmath>
class Solution {
public:
    int reverse(int x) {
    // if(x > INT_MAX || x < INT_MIN) return 0;
    long long n=0;
    while(x){
        n = n * 10 + (x%10);
        x /= 10;
    }
    if(n > INT_MAX || n < INT_MIN) return 0;
    return n;
    }
};