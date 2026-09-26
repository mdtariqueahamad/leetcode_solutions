// LeetCode Problem 3381: Maximum Subarray Sum With Length Divisible by K
// Difficulty: Medium
// Link: https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/
// Language: cpp

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        const long long INF = (long long)1e18;

        vector<long long> minPrefix(k, INF);
        minPrefix[k - 1] = 0;  // handle subarrays starting at index 0

        long long s = 0;
        long long ans = LLONG_MIN;

        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            int r = i % k;
            ans = max(ans, s - minPrefix[r]);
            minPrefix[r] = min(minPrefix[r], s);
        }

        return ans;
    }
};
