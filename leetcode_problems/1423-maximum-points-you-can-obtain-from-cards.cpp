// LeetCode Problem 1423: Maximum Points You Can Obtain from Cards
// Difficulty: Medium
// Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// Language: cpp

class Solution {
public:
    int maxScore(vector<int>& nums, int k){
        int sum = 0, mx = 0;
        for(int *low = &nums[0]; low < &nums[k]; low++)
            sum += *low;
        mx = sum;
        for(int *low = &nums[k-1], *high = &nums[nums.size()-1]; low >= &nums[0]; low--, high--){
            sum -= *low;
            sum += *high;
            mx = max(mx, sum);
        }
        return mx;
    }
};