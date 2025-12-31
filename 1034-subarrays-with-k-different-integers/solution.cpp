class Solution{
    int dummy(vector<int> nums, int k){
        int res = 0, res1 = 0;
        unordered_map<int,int> mpp;
        unordered_map<int,int> mpp1;
        for(int high = 0, low = 0, low1 = 0; high < nums.size(); high++){
            mpp[nums[high]]++;
            mpp1[nums[high]]++;
            while(mpp.size() > k){
                mpp[nums[low]]--;
                if(!mpp[nums[low]]) mpp.erase(nums[low]);
                low++;
            }
            while(mpp1.size() > k-1){
                mpp1[nums[low1]]--;
                if(!mpp1[nums[low1]]) mpp1.erase(nums[low1]);
                low1++;
            }
            res += (high - low + 1);
            res1 += (high - low1 + 1);
        }
        return res - res1;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k){
        return dummy(nums, k);
    }
};
