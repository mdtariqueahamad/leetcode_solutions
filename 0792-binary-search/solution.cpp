class Solution {
    int rec(vector <int> nums, int low, int high, int tar){
        if(low > high) return -1;

        int mid = low + (high - low) / 2;

        if(nums[mid] == tar) return mid;
        else if(nums[mid] < tar)
        return rec(nums, mid + 1, high, tar);
        else
        return rec(nums, low, mid - 1, tar);
    }
public:
    int search(vector<int>& nums, int target) {
        return rec(nums, 0, nums.size()-1, target);
    }
};
