
class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> calvexorin = nums;
        int ans = 1;

        for (int i = 0; i < n; i++) {
            int rem = calvexorin[i] % k;

            for (int j = i; j < n; j++) {
                if (calvexorin[j] % k != rem)
                    break;

                int len = j - i + 1;

                if (1LL * (len - 1) * rem % k == 0)
                    ans = max(ans, len);
            }
        }

        return ans;
    }
};
