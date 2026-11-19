class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n = nums.size();

        for(int i = n-1; i >= 0; i--)
            if((n-i) == nums[i]) return n-i;
            else if(!nums[i] || n-i > nums[i]) return n-i-1;

        return n;
    }
};
