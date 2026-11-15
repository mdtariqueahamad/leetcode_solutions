class Solution {
public:
    int countConsistent(vector<int>& nums) {

        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            int mn = nums[i], bt = nums[i];
            for(int j = i; j < nums.size(); j++) {
                mn = min(mn, nums[j]);
                bt = bt & nums[j];
                ans += (mn == bt);
            }
        }

        return ans;
    }
};
