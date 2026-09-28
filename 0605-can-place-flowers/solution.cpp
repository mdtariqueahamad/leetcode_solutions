class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {

        if(nums.size() == 1 && !nums[0] && (n == 0 || n == 1)) return true;

        if(nums.size() && !nums[0] && !nums[1]){
            nums[0] = 1;
            n--;
        }
        
        for(int i = 1; i < nums.size()-1; i++) {
            if(!nums[i-1] && !nums[i+1] && !nums[i]){
                n--;
                nums[i] = 1;
            }
        }

        if(nums.size() > 2 && !nums[nums.size()-2] && !nums[nums.size()-1]) n--;

        return n <= 0;

    }
};