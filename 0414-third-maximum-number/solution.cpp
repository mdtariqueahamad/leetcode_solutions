class Solution {
public:
    int thirdMax(vector<int>& nums){
       sort(nums.begin(), nums.end());
       int n = 2;
       int i = nums.size()-1;
       for(; n && i > 0 ; i--){
        if(nums[i] != nums[i-1]) n--;
       }
        if(n)  return nums[nums.size()-1];
       return nums[i];
    }
};
