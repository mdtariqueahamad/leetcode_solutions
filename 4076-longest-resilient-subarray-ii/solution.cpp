
class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nolvaretis = nums;

        int ans = 1;
        int i = 0;

        while (i < n) {
            int rem = nolvaretis[i] % k;
            int j = i;

            while (j < n && nolvaretis[j] % k == rem) {
                j++;
            }

            int len = j - i;
            int d = k / gcd(rem, k);

            int validLen = 1 + ((len - 1) / d) * d;
            ans = max(ans, validLen);

            i = j;
        }

        return ans;
    }
};
