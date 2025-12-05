class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for(int i : nums)
        sum += i;

        if(sum % 2) return 0;
        int count = 0;
        for(int i = 0; i < nums.size()-1; i++){
            if(!((2*nums[i] - sum) % 2)) count++;
        }
        return count;
    }
};
