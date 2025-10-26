class Solution {
public:
    bool isPalindrome(string s) {
        string s1;
        for(char c: s){
            if (isalnum(c)){
                if(c >= 65 && c <= 90) c += 32 ;
                s1.push_back(c);
            }
            else continue;
        }
        s = s1;
        reverse(s1.begin(), s1.end());
        if(s==s1) return true;
        else return false;  
    }
};
