class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
        unordered_map <int,int> mpp1;
        unordered_map <int,int> mpp2;
        for(int x : nums1)
        mpp1[x]++;

        for(int x : nums2)
        mpp2[x]++;
        nums1.clear();
        for(auto it : mpp1){
            bool freq = mpp1[it.first] && mpp2[it.first];
            if(freq)
                nums1.push_back(it.first);
        }
        return nums1;
    }
};
