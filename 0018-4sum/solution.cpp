class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int j = 0; j < n - 3; j++) {
            if (j > 0 && nums[j] == nums[j - 1]) continue; // skip duplicate j

            for (int i = j + 1; i < n - 2; i++) {
                if (i > j + 1 && nums[i] == nums[i - 1]) continue; // skip duplicate i

                int *left = & nums[i + 1], *right = &nums[n - 1];

                while (left < right) {
                    long long sum = (long long)nums[j] + nums[i] + *left + *right;

                    if (sum == target) {
                        res.push_back({nums[j], nums[i], *left, *right});

                        while (left < right && *left == *(left + 1)) left++;
                        while (left < right && *right == *(right - 1)) right--;

                        left++;
                        right--;
                    } 
                    else if (sum < target) left++;
                    else right--;
                }
            }
        }

        return res;
    }
};
