// LeetCode Problem 0027: Remove Element
// Difficulty: Easy
// Link: https://leetcode.com/problems/remove-element/
// Language: cpp

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(!nums.size()) return 0;
        int *start = &nums[0], *end = &nums[nums.size()-1];
        while(start <= end){
            if(*start == val){
                swap(*start, *end);
                end--;
                while(start < end && *end == val) end--;
            }
            else
            start++;
        }
        return end - nums.data() + 1;
    }
};