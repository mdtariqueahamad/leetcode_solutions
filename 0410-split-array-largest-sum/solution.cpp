class Solution {
public:
    int splitArray(vector<int>& nums, int k){
        if(k > nums.size() || !nums.size()) return -1;
       int low = INT_MIN, high = 0, res = INT_MAX;
       for(auto x : nums){
        low = max(low, x);
        high += x;
       }
       while(low <= high){
        int mid = (low + high) / 2;
        int sum = 0, maxs = 0, count = 1;
        for(int x : nums){
            if(sum + x > mid){
                sum = 0;
                count++;
            }
            sum += x;
        }
        if(count > k) low = mid + 1;
        else{
            high = mid - 1;
            res = min(mid,res);
        }
       }
       return res;
    }
};
