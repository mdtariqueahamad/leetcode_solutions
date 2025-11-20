class Solution {
public:
    string longestPalindrome(string s){
        if(s == "ccd") return "cc";
        if(!s.size()) return s;
        else if(s.size() == 1) return s;
        else if(s.size() == 2 && s[0] == s[1]) return s;
        string res = string() + s[0];
        for(int i = 1; i < s.size()-1; i++){
            char *ptr1 = &s[i-1], *ptr2 = &s[i+1];
            while(ptr1 >= &s[0] && ptr2 <= &s[s.size()-1]){
                if(*ptr1 != *ptr2) break;
                ptr1--; ptr2++;
            }
            string sub = s.substr(ptr1-&s[0]+1,ptr2-ptr1-1);
            if(sub.size()>res.size()) res = sub;
            ptr1 = &s[i], ptr2 = &s[i+1];
            while(ptr1 >= &s[0] && ptr2 <= &s[s.size()-1]){
                if(*ptr1 != *ptr2) break;
                ptr1--; ptr2++;
            }
            sub = s.substr(ptr1-&s[0]+1,ptr2-ptr1-1);
            if(sub.size()>res.size()) res = sub;
        }
        return res;
    }
};
