class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);

        for(int i = 0; i <= n; i++){
            int j = i, count = 0;
            while(j){
                count += (j&1);
                j >>= 1;
            }
            ans[i] = count;
        }

        return ans;
    }
};