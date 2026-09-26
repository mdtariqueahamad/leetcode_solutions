// LeetCode Problem 0034: Find First and Last Position of Element in Sorted Array
// Difficulty: Medium
// Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Language: cpp

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                int mid1 = mid;
                for (; mid >= 0 && nums[mid] == target; mid--) {
                }
                mid++;
                for (; mid1 < nums.size() && nums[mid1] == target; mid1++) {
                }
                mid1--;
                return {mid,mid1};
            } else if (nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return {-1, -1};
    }
};