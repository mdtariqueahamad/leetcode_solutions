class Solution {
public:
    long long maxSum(vector<int>& nums, int k) {
        vector<int> freq(31, 0);

        for (int n : nums) {
            for (int i = 0; i < 31; i++) {
                if (n & (1 << i)) freq[i]++;
            }
        }

        long long ans = 0;

        while (k--) {
            long long num = 0;

            for (int i = 0; i < 31; i++) {
                if (freq[i] > 0) {
                    num |= (1LL << i);
                    freq[i]--;
                }
            }

            ans = (ans + num * num) % 1000000007;
        }

        return ans;
    }
};