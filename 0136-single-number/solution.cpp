class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = 0;
        for(int i: nums){
            n ^= i;
        }
        return n;
    }
};
