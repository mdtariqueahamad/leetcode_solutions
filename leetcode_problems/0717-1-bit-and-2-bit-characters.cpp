// LeetCode Problem 0717: 1-bit and 2-bit Characters
// Difficulty: Easy
// Link: https://leetcode.com/problems/1-bit-and-2-bit-characters/
// Language: cpp

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = bits.size() - 2;
        int count = 0;
        while (i >= 0 && bits[i] == 1) {
            count++;
            i--;
        }
        return (count % 2 == 0);
    }
};
