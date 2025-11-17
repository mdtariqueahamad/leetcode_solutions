class Solution {
public:
    bool isIsomorphic(string s, string t){
        if(s.size() != t.size()) return false;
        unordered_map <int,int> sm;
        unordered_map <int,int> tm;
        for(int i = 0; i < s.size(); i++){
            if(sm[s[i]] != tm[t[i]]) return false;
            sm[s[i]] = i+1;
            tm[t[i]] = i+1;
        }
        return true;
    }
};
