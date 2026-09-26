// LeetCode Problem 2595: Number of Even and Odd Bits
// Difficulty: Easy
// Link: https://leetcode.com/problems/number-of-even-and-odd-bits/
// Language: cpp

class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0, odd = 0;
        for(int i = 0; n ; i++){
            if(n&1 && i%2){
                odd++;
            }
            else if(n&1 && !(i%2)){
                even++;
            }
            n >>= 1;
        }
        return {even,odd};
    }
};