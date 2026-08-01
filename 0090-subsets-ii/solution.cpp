class Solution {
public:
    void func(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int idx){
        if(idx == nums.size()) return;
        
        temp.push_back(nums[idx]);
        if(find(ans.begin(),ans.end(), temp) == ans.end())
        ans.push_back(temp);
        func(nums, ans, temp, idx+1);
        temp.pop_back();
        func(nums, ans, temp, idx+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int> nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> ans = {{}};
        func(nums, ans, temp, 0);
        return ans;
    }
};
