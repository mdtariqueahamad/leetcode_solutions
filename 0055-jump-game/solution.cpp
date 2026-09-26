class Solution {
public:
    bool canJump(vector<int>& nums) {
        int c = 0;
        for(int i = 0; i < nums.size()-1; i++){
        if(!nums[i] && !c){
            return false;
        }
        else{
            c = max(c, nums[i]);
            if((i + nums[i]) >= (nums.size()-1)) return true;
        }
        c--;
        }

        return true;
    }
};