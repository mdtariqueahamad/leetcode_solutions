// LeetCode Problem 0069: Sqrt(x)
// Difficulty: Easy
// Link: https://leetcode.com/problems/sqrtx/
// Language: cpp

class Solution {
public:
    int mySqrt(int n) {
        long long low = 1, high = n;
        while(low <= high){
            long long mid = (low + high)/2;
            if(mid*mid == n) return (int)mid;
            else if(mid*mid < n) low = mid + 1;
            else high = mid - 1;
        }
        return (int)low-1;
    }
};