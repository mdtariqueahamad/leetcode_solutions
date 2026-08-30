class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxm, minm, minidx = 0, maxidx = 0;
        maxm = minm = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(maxm < nums[i]){
                maxm = nums[i];
                maxidx = i;
            }
            if(minm > nums[i]){
                minm = nums[i];
                minidx = i;
            }
        }
        maxm = max(maxidx, minidx);
        minm = min(maxidx, minidx);
        int ans = maxm + 1;
        ans = min(ans, n - minm);
        return min(ans, minm+1+(n-maxm));
    }
};
