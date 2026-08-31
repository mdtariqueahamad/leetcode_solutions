class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> visited;
    void solve(vector<int> &nums, int idx) {
        if(nums.size() == idx) return;
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        if(!visited[idx]){
        temp.push_back(nums[idx]);
        visited[idx] = true;
        solve(nums, 0);
        temp.pop_back();
        visited[idx] = false;}
        solve(nums, idx+1);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        visited = vector<bool>(nums.size(), false);
        solve(nums, 0);
        return ans;
    }
};
