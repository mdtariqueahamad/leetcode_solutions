class Solution {
public:
    int countDominantElements(vector<int>& nums) {

        if(1 == nums.size()) return 1;

        int count = 0;
        
        if(nums[0] >= nums[1]) count++;
        if(nums[nums.size()-1] >= nums[nums.size()-2]) count++;

        for(int i = 1; i < nums.size()-1; i++) {
            int avg = (nums[i+1] + nums[i-1] + 1) / 2;
            if(nums[i] >= avg) count++;
        }

        return count;
    }
};
