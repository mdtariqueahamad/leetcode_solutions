class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0; int j = nums.size()-1;
        int n;
        while(i <= j){
            n = (i + j)/2;
            if(nums[n] == target) return n;
            else if(nums[n] > target) j = n - 1;
            else i = n + 1;
        }
        return -1;
    }
};
