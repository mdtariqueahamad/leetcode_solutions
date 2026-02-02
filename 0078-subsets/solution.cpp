class Solution {
    void print(vector <int> nums, vector<int> &ans, vector<vector<int>> &res, int i){
    if(i == nums.size()){
        res.push_back(ans);
        return;
    }
    ans.push_back(nums[i]);
    print(nums, ans, res, i+1);
    ans.pop_back();
    print(nums, ans, res, i+1);
}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector <int>> res;
        vector<int> ans;
        print(nums, ans, res, 0);
        return res;
    }
};
