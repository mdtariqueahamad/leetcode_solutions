class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int x : nums){
            if(mp[x]) mp[x] = 0;
            else mp[x] = 1;
        }
        vector<int> res(2);
        int i = 0;
        for(auto x : mp){
            if(x.second) res[i++] = x.first;
        }
        return res;
    }
};
