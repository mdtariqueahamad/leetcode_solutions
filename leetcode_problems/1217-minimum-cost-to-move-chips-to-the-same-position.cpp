// LeetCode Problem 1217: Minimum Cost to Move Chips to The Same Position
// Difficulty: Easy
// Link: https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
// Language: cpp

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;
        for (int x : position)
            x % 2 ? odd++ : even++;
        return min(odd, even);
    }
};
