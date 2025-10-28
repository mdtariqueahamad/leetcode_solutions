class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int *left = &nums[i+1];
            int *right = &nums[nums.size()-1];
            while(left < right){
            if(!(nums[i]+ *left + *right)){
            res.push_back({nums[i], *left, *right});
            while (left < right && *left == *(left + 1)) left++;
            // while (left < right && *right == *(right - 1)) right--;
            right--;
            left++;
            }
            else if((nums[i]+ *left + *right)>0)
            right--;
            else
            left++;
            }
        }
        return res;
    }
};
