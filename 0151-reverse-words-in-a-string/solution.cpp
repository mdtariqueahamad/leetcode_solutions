class Solution {
public:
    string reverseWords(string s) {
        string str;
        string res;
        for(auto x : s){
            if(x == ' '){
            if(str == " " || str.empty()){
                str = "";
                continue;
            }
              str = " " + str;
              res = str + res;
              str = "";
              continue;
            }
            str += x;
        }
        res = str + res;
        if(res.size() && res[0] == ' ') res.erase(0,1);
        return res;
    }
};
