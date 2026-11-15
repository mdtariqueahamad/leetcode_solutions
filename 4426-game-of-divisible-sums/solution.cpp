class Solution {
public:
    long long maxDifference(vector<int>& nums) {

        vector<long long> dp(nums.size()+2, 0);

        for(int i = nums.size()-1; i >= 0; i--) {
            long long sum1 = nums[i];

            long long op1 = sum1 + (!(sum1 % 3)? -dp[i+1]: dp[i+1]);

            long long op2 = LLONG_MIN;

            if(i+1 < nums.size()) {
                long long sum2 = nums[i] + nums[i+1];

                op2 = sum2 + (!(sum2%3)? -dp[i+2]: dp[i+2]);
            }

            dp[i] = max(op1, op2);
        }

        return dp[0];
    }
};
