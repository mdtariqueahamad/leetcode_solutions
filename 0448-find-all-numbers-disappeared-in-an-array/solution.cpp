class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        int n = nums.size();

        for(int i = 1; i <= n; i++){
            while(nums[i-1] != i && nums[nums[i-1]-1] != nums[i-1]){
                swap(nums[i-1], nums[nums[i-1]-1]);
            }
        }

        vector<int> ans;

        for(int i = 0; i < n; i++)
            if(nums[i] != i+1) ans.push_back(i+1);

        return ans;
    }
};