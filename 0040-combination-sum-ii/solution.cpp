class Solution {
public:
    void func(vector<int>& nums, int target, int idx,
              vector<int>& temp, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (idx == nums.size() || target < 0)
            return;

        temp.push_back(nums[idx]);
        func(nums, target - nums[idx], idx+1, temp, ans);
        temp.pop_back();

        while(idx < nums.size()-1 && nums[idx+1] == nums[idx])
            idx++;
        func(nums, target, idx+1, temp, ans);
    }
    vector<vector<int>> combinationSum2(vector<int> v, int target) {
        sort(v.begin(), v.end());
        vector<int> temp;
        vector<vector<int>> ans;
        func(v, target, 0, temp, ans);
        return ans;
    }
};
