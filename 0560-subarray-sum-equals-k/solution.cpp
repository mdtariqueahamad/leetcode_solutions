class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector <int> prefixSum(nums.size());
        int count = 0;
        prefixSum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
            prefixSum[i] = prefixSum[i-1] + nums[i];
        
        unordered_map <int, int> freq;
        for(int i = 0; i < nums.size(); i++){
        if(prefixSum[i] == k) count++;
        int val = prefixSum[i] - k;
        if(freq.find(val) != freq.end()) count += freq[val];
        if(freq.find(prefixSum[i]) == freq.end()) freq[prefixSum[i]] = 0;
        freq[prefixSum[i]]++;
        }
        return count;
    }
};
