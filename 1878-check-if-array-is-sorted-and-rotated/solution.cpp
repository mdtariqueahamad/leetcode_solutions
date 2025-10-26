class Solution {
public:
    bool check(vector<int>& nums) {
        int n = 0;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i-1]>nums[i]){
                if(!n && nums[0]>=nums[nums.size()-1]){ n++; continue;}
                return false;
            }
        }
        return true;
    }
};
