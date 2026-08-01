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

        // Take current element
        temp.push_back(nums[idx]);
        func(nums, target - nums[idx], idx, temp, ans);
        temp.pop_back();

        // Skip current element
        func(nums, target, idx + 1, temp, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        func(candidates, target, 0, temp, ans);

        return ans;
    }
};
