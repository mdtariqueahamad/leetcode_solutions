class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector <int>> res;
        int n = nums.size();
        int n1 = 1<<n;
        for(int i=0; i<n1; i++){
            vector <int> temp(0);
            for(int j=0; j<n; j++){
                if(i&(1<<j))
                temp.push_back(nums[j]);
            }
            res.push_back(temp);
        }
        return res;
    }
};
