class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for(int i = nums[0], idx = 0; i < nums[nums.size()-1]; i++)
            if(i != nums[idx]) ans.push_back(i);
            else idx++;
        return ans;
    }
};
