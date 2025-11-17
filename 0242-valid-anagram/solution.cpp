class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.size()) return false;
        unordered_map <int,int> sm;
        unordered_map <int,int> tm;
        for(int i = 0; i < s.size(); i++){
            sm[s[i]]++; tm[t[i]]++;
        }
        return sm == tm;
    }
};
