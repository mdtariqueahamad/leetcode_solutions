class Solution {
public:
    long long minCost(vector<int>& nums) {

        int n =  nums.size();
        if(n < 3) return 0;

        long long ans = LLONG_MAX;
        int i = 0;

        while(i < n) {
            int j = i;

            while(j + 1 < n && nums[j+1] == nums[i])
                j++;

            if(j >= 1 && i <= n-2) {
                long long cover = i+(n-j-1);
                ans = min(ans, cover*nums[i]);
            }

            i = j+1;
        }

        return ans;
    }
};
