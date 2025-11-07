class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int j = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < j) continue;
            if (nums[i] == j) j++;
            else if (nums[i] > j) break;
        }

        return j;
    }
};
