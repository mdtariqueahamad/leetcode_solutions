class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector <int> res(nums1.size());
        unordered_map<int,int> mp;
        for(int i = 0; i < nums2.size(); i++)
            mp[nums2[i]] = i;

        for(int i = 0; i < nums1.size(); i++){
            bool fill = false;
            if(mp.find(nums1[i]) != mp.end()){
                for(int j = mp[nums1[i]]+1; j < nums2.size(); j++){
                    if(nums2[j] > nums1[i]){
                        res[i] = nums2[j];
                        fill = true;
                        break;
                    }
                }
                if(!fill) res[i] = -1;
            } else{
                res[i] = -1;
            }
        }
        return res;
    }
};
