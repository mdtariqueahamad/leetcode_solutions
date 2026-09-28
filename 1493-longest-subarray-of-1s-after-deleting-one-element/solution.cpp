class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int low = 0, high = 0, temp, mx = 0;

        while(high < nums.size()){
            while(low < nums.size() && !nums[low]) low++;

            high = low;

            while(high < nums.size() && nums[high]) high++;
            temp = high;

            if (high < nums.size()-1 && nums[high+1]) {

                temp = high+1;

                while(temp < nums.size() && nums[temp]) temp++;
                mx = max(mx, temp-low-1);

            }

                mx = max(mx, high-low);
                low = high+1;
        }

        if(mx == nums.size()) return mx-1;
        return mx;
    }
};