class Solution {
    typedef long long ll;
public:
    long long minCost(vector<int>& nums) {

        int n = nums.size();
        ll ans = (ll)nums[0] + nums[n-1];

        ll negCount = 0, minAbs = LLONG_MAX;

        for(int i = 1; i < n-1; i++) {

            if(nums[i] < 0) {
                
                ans += nums[i];
                negCount++;
            }

            minAbs = min(minAbs, (ll)abs(nums[i]));
        }

        if(negCount % 2) ans += minAbs;

        return ans;
    }
};
