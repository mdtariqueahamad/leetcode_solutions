class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> minn = nums;

        for(int i = nums.size()-2; i >= 0; i--)
            minn[i] = min(minn[i], minn[i+1]);
        
        int largest = nums[0];

        for(int i = 0; i < nums.size(); i++){
            largest = max(largest, nums[i]);
            if(k >= largest - minn[i]) return i;
        }

        return -1;
    }
};
