class Solution {
    vector<int> dp;

    int solve(vector<int> &nums, int idx) {

        if(nums.size() <= idx) return 0;

        if(-1 != dp[idx]) return dp[idx];

        int plus_1 = solve(nums, idx+1),
        plus_2 = solve(nums, idx+2);

        return dp[idx] = nums[idx] + min(plus_1, plus_2);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {

        dp.assign(cost.size(), -1);
        
        return min(solve(cost, 0), solve(cost, 1));
    }
};
