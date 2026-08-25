class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int f = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == (k * f)) f++;
        }
        return k * f;
    }
};
