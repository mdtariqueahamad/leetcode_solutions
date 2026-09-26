// LeetCode Problem 0507: Perfect Number
// Difficulty: Easy
// Link: https://leetcode.com/problems/perfect-number/
// Language: cpp

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for(int i = 1; i <= num / 2; i++){
            if(!(num % i)){
                sum += i;
            }
        }
        return sum == num;
    }
};