class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> nums(pow(2,n));
        for(int i = 0; i < pow(2,n); i++){
            nums[i] = i ^ (i >> 1);
        }
        return nums;
    }
};
