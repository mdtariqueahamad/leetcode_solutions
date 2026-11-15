class Solution {
    int MOD = 1e9+7;
public:
    int numOfSubarrays(vector<int>& arr) {
        
        vector<int> prefixSum(arr.size(), 0);
        prefixSum[0] = arr[0];

        for(int i = 1; i < prefixSum.size(); i++)
            prefixSum[i] = prefixSum[i-1] + arr[i];

        int ans = 0;

        for(int i = 0, even = 1, odd = 0; i < arr.size(); i++) {
            if(prefixSum[i] & 1) {

                ans = (ans + even) % MOD;
                odd++;

            } else {

                ans = (ans + odd) % MOD;
                even++;

            }
        }

        return ans;
    }
};
