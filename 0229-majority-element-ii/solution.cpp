class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i : nums){
            if(mp.find(i) == mp.end()) mp[i] = 1;
            else mp[i]++;
        }
        vector <int> res;
        for(auto &i : mp){
            if(i.second>(nums.size()/3)){
                res.push_back(i.first);
            }
        }
        return res;
    }
};
