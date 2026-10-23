class Solution {
    pair<bool,int> dec(vector<int> nums) {

        reverse(nums.begin(), nums.end());

        return {inc(nums), nums.back()};
    }

    bool inc(vector<int> &nums) {

        int n = nums.size();

        for(int i = 1; i < n; i++)
            if(nums[i] != (nums[i-1] + 1) % n)
                return false;

        return true;
    }
public:
    int minOperations(vector<int>& nums) {

        int n = nums.size();

        pair<int,int> dc = dec(nums);

        if(inc(nums)) {
            return min(n-nums.back()-1, nums.back()+3);
        } else if(dc.first) {
            return min(n-dc.second, dc.second + 2);
        } else {
            return -1;
        }
    }
};