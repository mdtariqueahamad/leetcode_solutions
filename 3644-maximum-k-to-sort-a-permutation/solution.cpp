class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        
        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            if(i != nums[i]) ans &= nums[i];
        } 

        return ans == INT_MAX? 0: ans;
    }
};