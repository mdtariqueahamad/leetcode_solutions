class Solution {

    vector<int> dp;

    int solve(vector<int> &nums, int idx) {

        if(nums.size() <= idx) return 0;
        if(dp[idx] != -1) return dp[idx];

        int ammount = 0;
        for(int i = idx+2; i < nums.size(); i++) {
            ammount = max(ammount, solve(nums, i));
        }

        return dp[idx] = nums[idx] + ammount;
    }
public:
    int rob(vector<int>& nums) {
        
        dp.assign(nums.size(), -1);
        return max(solve(nums, 0), solve(nums, 1));
    }
};
