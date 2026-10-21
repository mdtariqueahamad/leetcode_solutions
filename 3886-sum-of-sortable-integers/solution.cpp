class Solution {

    bool checkRotated(vector<int>& nums, int low, int high) {
        bool check = false;

        for (int i = low + 1; i < high; i++) {
            if (nums[i - 1] > nums[i]) {
                if (check) return false;
                check = true;
            }
        }

        if (nums[high - 1] > nums[low]) {
            if (check) return false;
        }

        return true;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;
            int prevMax = INT_MIN;

            for (int i = 0; i < n; i += k) {
                
                int currMin = *min_element(
                    nums.begin() + i,
                    nums.begin() + i + k
                );

                int currMax = *max_element(
                    nums.begin() + i,
                    nums.begin() + i + k
                );

                if (currMin < prevMax ||
                    !checkRotated(nums, i, i + k)) {
                    valid = false;
                    break;
                }

                prevMax = currMax;
            }

            if (valid) ans += k;
        }

        return ans;
    }
};