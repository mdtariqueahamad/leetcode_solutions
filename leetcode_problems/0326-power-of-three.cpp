// LeetCode Problem 0326: Power of Three
// Difficulty: Easy
// Link: https://leetcode.com/problems/power-of-three/
// Language: cpp

class Solution {
public:
    bool isPowerOfThree(int n){
        if(n <= 0) return  false;
        float x = log(n)/log(3);
        return pow(3,x) == n;
    }
};