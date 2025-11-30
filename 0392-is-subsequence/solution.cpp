class Solution {
public:
    bool isSubsequence(string s, string t) {
        char *sp = &s[0], *tp = &t[0];
        while(sp < &s[s.size()] && tp < &t[t.size()]){
            if(*sp == *tp) sp++;
            tp++;
        }
        return sp == &s[s.size()];
    }
};
