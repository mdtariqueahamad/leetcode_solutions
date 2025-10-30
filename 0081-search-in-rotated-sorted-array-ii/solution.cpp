class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        for(int i = 1; i < nums.size(); i++)
            if(nums[i-1] > nums[i]){
                if(target <= nums[i-1] && target >= nums[0])
                end = i-1;
                else if(target >= nums[i] && target <= nums[end])
                start = i;
                break;
            }

            while(start <= end){
                int mid = (start + end)/2;
                if(nums[mid] == target) return true;
                else if(nums[mid] > target) end = mid - 1;
                else start = mid + 1;
            }
            return false;
    }
};
