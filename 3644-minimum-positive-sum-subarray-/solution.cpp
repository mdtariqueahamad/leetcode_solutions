class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        
        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            int sum = 0, len = 0;

            for(int j = i; j < nums.size() && len < r; j++) {
                
                sum += nums[j];
                len++;

                if(len >= l && sum > 0) ans = min(ans, sum);
            }
        }

        return ans == INT_MAX? -1: ans;
    }
};
