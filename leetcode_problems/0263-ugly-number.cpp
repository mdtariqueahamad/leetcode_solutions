// LeetCode Problem 0263: Ugly Number
// Difficulty: Easy
// Link: https://leetcode.com/problems/ugly-number/
// Language: cpp

class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0) return false;
        while(n){
        if(n == 1) return true;
            if(n % 2){
                if(n % 3){
                    if(n % 5){
                        return false;
                    }
                    n /= 5;
                    continue;
                }
                n /= 3;
                continue;
            }
            n /= 2;
        }
        return true;
    }
};