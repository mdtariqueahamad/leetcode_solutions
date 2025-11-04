class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector <int> res;
        for(int x : nums1){
            for(int y : nums2){
                if( x == y && find(res.begin(), res.end(), x) == res.end())
                res.push_back(x);
            }
        }
        return res;
    }
};
