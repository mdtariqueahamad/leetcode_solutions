class Solution{
public:
    int longestOnes(vector<int>& nums, int k){
        int i = 0, j = 0, zero = 0, mx = 0;
        for( ; j < nums.size(); j++){
            if(!nums[j]) zero++;
            if(zero > k){
                while(zero > k){
                    if(!nums[i]) zero--;
                    i++;
                }
            }
            mx = max(mx, j-i+1);
        }
        return mx;
    }
};
