class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> nums(n);

        for (int i = 0; i < n; i++)
            nums[i] = abs(nums1[i] - nums2[i]);

        sort(nums.begin(), nums.end(), greater<long long>());

        long long k = (long long)k1 + k2;

        long long cur = nums[0];
        int j = 0;

        while (k > 0 && cur > 0) {
            while (j < n && nums[j] == cur) j++;

            long long next = (j < n) ? nums[j] : 0;
            long long cost = (cur - next) * j;

            if (k >= cost) {
                k -= cost;
                cur = next;
            } else {
                long long q = k / j;
                long long r = k % j;
                cur -= q;
                for (int t = 0; t < j; t++)
                    nums[t] = cur - (t < r ? 1 : 0);
                k = 0;
                j = -1;
            }
        }

        if (j != -1)
            for (int t = 0; t < j; t++) nums[t] = cur;

        long long ans = 0;
        for (long long x : nums) ans += x * x;
        return ans;
    }
};