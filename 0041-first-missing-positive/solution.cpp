class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        for(int i = 1; i <= nums.size(); i++){
            while(nums[i-1] > 0 && nums[i-1] <= nums.size() && nums[i-1] != i && nums[i-1] != nums[nums[i-1]-1]) {
                swap(nums[i-1], nums[nums[i-1]-1]);
            }
        }

        for (int i = 0; i < nums.size(); i++)
            if(i+1 != nums[i]) return i+1;
        
        return nums.size()+1;
    }
};
