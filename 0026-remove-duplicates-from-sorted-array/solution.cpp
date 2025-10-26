class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size()) return 0;
        int n = 0;
        vector <int> res;
        res.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]!=res[n]){
                n++;
                res.push_back(nums[i]);
            }
        }
        nums = res;
        return nums.size();
    }
};
