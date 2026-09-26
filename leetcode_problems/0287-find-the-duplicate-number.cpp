// LeetCode Problem 0287: Find the Duplicate Number
// Difficulty: Medium
// Link: https://leetcode.com/problems/find-the-duplicate-number/
// Language: cpp

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow, fast;
        slow = fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(slow != fast);

        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};