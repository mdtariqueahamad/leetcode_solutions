class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());

        int start = 0, end = nums.size();

        for( ; start < nums.size(); start++)
            if(nums[start] == target) {
                end = start + 1;
                while(end < nums.size() && nums[end] == target) end++;
                break;
            }

        vector<int> ans(end-start);
        iota(ans.begin(), ans.end(), start);
        
        return ans;
    }
};