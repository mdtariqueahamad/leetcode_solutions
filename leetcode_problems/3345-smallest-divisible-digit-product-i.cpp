// LeetCode Problem 3345: Smallest Divisible Digit Product I
// Difficulty: Easy
// Link: https://leetcode.com/problems/smallest-divisible-digit-product-i/
// Language: cpp

class Solution {
public:
    int smallestNumber(int n, int t) {
            while(n < 10){
                if(!(n % t)) return n;
                n++;
            }
        int n0 = n%10, n1 = n/10;
                while(n1<=10){
                    while(n0 < 10){
                        if(!((n0*n1)%t)) return n1*10+n0;
                        n0++;
                    }
                    n0 = 0;
                    n1++;
                }
                return 0;
    }
};