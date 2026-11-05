class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int count = INT_MAX, sum = 0, idx = 0, low = 0;

        while(idx < nums.size() || sum >= target) {

            while(low < idx && sum >= target) {
                count = min(count, idx-low);
                sum -= nums[low];
                low++;
            }

            while(idx < nums.size() && sum < target) {
                sum += nums[idx];
                idx++;
            }

            if(sum >= target) count = min(count, idx-low);
        }

        return count == INT_MAX? 0: count;
    }
};
