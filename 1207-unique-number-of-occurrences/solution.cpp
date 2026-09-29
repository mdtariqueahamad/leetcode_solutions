class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int,int> mpp;

        for(int x: arr) mpp[x]++;

        unordered_map<int,int> mpp1;

        for(auto it: mpp){
            mpp1[it.second]++;
            if(mpp1[it.second] > 1) return false;
        }

        return true;
    }
};