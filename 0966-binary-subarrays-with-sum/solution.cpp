class Solution{
public:
    int numSubarraysWithSum(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int low = 0, high = 0, sum = 0, countSub = 0, countSmall = 0;
        for( ; low < nums.size(); low++){
            sum += nums[low];
                while((high < nums.size()) && (sum > goal)){
                    sum -= nums[high];
                    high++;
                }
            countSub += (low - high + 1);
        }
        if(goal == 0) return countSub;
        low = high = sum = 0;
        for( ; low < nums.size(); low++){
            sum += nums[low];
                while((high < nums.size()) && (sum > (goal-1))){
                    sum -= nums[high];
                    high++;
                }
            countSmall += (low - high + 1);
        }
        return countSub - countSmall;
    }
};
