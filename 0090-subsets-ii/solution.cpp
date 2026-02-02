class Solution {
    void print(vector <int> nums, vector<int> &ans, int i, vector<vector<int>> &res){
    if(i == nums.size()){
        res.push_back(ans);
        return;
    }
    ans.push_back(nums[i]);
    print(nums, ans, i+1, res);
    i++;
    while(i < nums.size() && nums[i-1] == nums[i]) i++;
    ans.pop_back();
    print(nums, ans, i, res);
}
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> ans;
        print(nums, ans, 0, res);

        return res;
    }
};
