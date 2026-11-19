class Solution {
public:
    int hIndex(vector<int>& nums) {

        sort(begin(nums), end(nums));
        int n = nums.size(), i = n-1, count = 0;

        for(; i >= 0; i--) {
            if((n-i) == nums[i]) return n-i;
            else if(!nums[i] || n-i > nums[i]) return count;

            count++;
        }

        return n-i-1;
    }
};
