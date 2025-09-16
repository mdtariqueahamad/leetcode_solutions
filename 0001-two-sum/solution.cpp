class Solution {
public:
        vector<int> twoSum(vector<int>& nums, int target) {
        for(int i; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(target == nums[i]+nums[j])
                return {i,j};
            }
        }
        return {}; 
        }
};
