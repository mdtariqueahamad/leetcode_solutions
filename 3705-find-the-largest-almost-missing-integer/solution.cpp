class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(!nums.size()) return -1;
        unordered_map<int, int> vec;
        for(int i = 0; i < nums.size(); i++){
            vec[nums[i]]++;
        }
        if(nums.size() == k) return *max_element(nums.begin(), nums.end());
        if (k == 1) {
            int ans = -1;

            for (auto x : vec) {
                if (x.second == 1)
                    ans = max(ans, x.first);
            }

            return ans;
        }
        if(vec[nums[nums.size()-1]] >= 2 && vec[nums[0]] >= 2) return -1;
        if(vec[nums[0]] > 1) return nums[nums.size()-1];
        if(vec[nums[nums.size()-1]] > 1) return nums[0];
        return max(nums[0], nums[nums.size()-1]);
    }
};
