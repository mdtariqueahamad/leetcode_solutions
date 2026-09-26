// LeetCode Problem 1437: Check If All 1's Are at Least Length K Places Away
// Difficulty: Easy
// Link: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
// Language: cpp

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
       int last = -1;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i]){
                if(last != -1 && i - last - 1 < k) return false;
                last = i;
            }
        return true;
    }
};