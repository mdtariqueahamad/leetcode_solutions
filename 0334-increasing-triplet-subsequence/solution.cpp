class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        int small = nums[0], mid = INT_MAX;

        for(int x: nums){
            small = min(small, x);
            if(x > small) mid = min(mid, x);
            if(small < mid && mid < x) return true;
        }

        return false;
    }
};