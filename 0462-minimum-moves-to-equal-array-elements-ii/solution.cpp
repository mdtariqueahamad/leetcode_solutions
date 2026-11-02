class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        n = n & 1? nums[n/2] : (nums[n/2]+nums[(n/2)-1])/2;
        
        int sum = 0;
        
        for(int x: nums)
            sum += abs(x-n);
            
        return sum; 
    }
};
