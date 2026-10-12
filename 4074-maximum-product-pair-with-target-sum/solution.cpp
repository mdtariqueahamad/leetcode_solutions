
class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        long long best = LLONG_MIN;
        vector<int> ans = {-1, -1};

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            auto it = mpp.find(complement);

            if (it != mpp.end()) {
                int k = it->second;

                if (nums[k] > nums[i]) {
                    long long prod = 1LL * nums[k] * nums[i];

                    if (prod > best) {
                        best = prod;
                        ans = {k, i};
                    }
                } else if (nums[i] > nums[k]) {
                    long long prod = 1LL * nums[i] * nums[k];

                    if (prod > best) {
                        best = prod;
                        ans = {i, k};
                    }
                }
            }

            mpp[nums[i]] = i;
        }

        return ans;
    }
};
