class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), min = INT_MAX, res = target;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-2; i++){
            int need = target - nums[i], low = i+1, high = n-1;
            while(low < high){
                int diff = need - (nums[low] + nums[high]);
                if(abs(diff) < min){
                    res = nums[low] + nums[high] + nums[i];
                    min = abs(diff);
                }
                if(diff < 0) high--;
                else if(diff > 0) low++;
                else return target;
            }
        }
        return res;
    }
};
