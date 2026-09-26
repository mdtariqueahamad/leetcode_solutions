// LeetCode Problem 3190: Find Minimum Operations to Make All Elements Divisible by Three
// Difficulty: Easy
// Link: https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/
// Language: cpp

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        for(auto x : nums){
            if(x % 3 == 1) count++;
            else if(x % 3 == 2) count++;
        }
        return count;
    }
};