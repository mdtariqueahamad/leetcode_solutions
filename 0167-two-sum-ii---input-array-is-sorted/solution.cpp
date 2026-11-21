class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int *low = nums.data(), *high = nums.data() + nums.size()-1;

        while(low < high)

            if(*low + *high < target) low++;
            else if(*low + *high > target) high--;
            else return {
                int(low-nums.data()+1),
                int(high-nums.data()+1)
                };

        return {};
    }
};
