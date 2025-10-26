class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector <int> res(nums.size());
            int i = 0, j = 1;
        for(int ans : nums){
            if(ans > 0){
                res[i] = ans;
                i += 2;
            }
            else if(ans < 0){
                res[j] = ans;
                j += 2;
            }
        }
        return res;
    }
};
