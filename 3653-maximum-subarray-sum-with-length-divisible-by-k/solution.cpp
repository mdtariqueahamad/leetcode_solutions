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

