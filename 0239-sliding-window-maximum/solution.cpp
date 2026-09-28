class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){

        for(int i = 0; i<nums.size(); i++){
            for(int j = i-1; j>=0 && (i-j) < k && nums[j]<nums[i]; j--)
            nums[j] = nums[i];
        }

        while(--k) nums.pop_back();

        return nums;
    }
};