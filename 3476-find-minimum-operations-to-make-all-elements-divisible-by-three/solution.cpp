class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        for(auto x : nums){
            if(x % 3 == 1) count++;
            else if(x % 3 == 2) count++;
        }
        return count;
    }
};
