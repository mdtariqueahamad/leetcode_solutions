class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int ans = 1, inc = 1, dec = 1;

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i-1] > nums[i]) {
                inc = 1;
                dec++;
                ans = max(dec, ans);
            } else if(nums[i-1] < nums[i]) {
                dec = 1;
                inc++;
                ans = max(inc, ans);
            } else inc = dec = 1;
        }

        return ans;
        
    }
};
