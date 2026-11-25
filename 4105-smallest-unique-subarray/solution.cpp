class Solution {
    static constexpr long long MOD = 100000000;

    bool check(vector<int> &nums, int n) {

        unordered_map<int, int> mpp;
        long long power = 1;

        for(int i = 0; i < n; i++)
            power = (power * 10) % MOD;
        
        long long hash = 0;
        for(int i = 0; i < n; i++)
            hash = (hash * 10 + nums[i]) % MOD;

        mpp[hash]++;

        for(int i = n, low = 0; i < nums.size(); i++, low++) {
            hash = (hash * 10 + nums[i] - (nums[i - n] * power) % MOD + MOD) % MOD;
            mpp[hash]++;
        }

        for(auto it: mpp) {
            if(1 == it.second) return true;
        }

        return false;
    }

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        
        int low = 1, high = nums.size();

        while(low < high) {

            int mid = low + (high - low) / 2;

            if(check(nums, mid)) high = mid;
            else low = mid + 1;
        }

        return low;
    }
};
