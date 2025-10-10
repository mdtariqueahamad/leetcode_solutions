class Solution {
public:
    string convertToTitle(int inp) {
        string res;
        while(inp){
            char c;
            if(inp%26) c = inp % 26 + 64;
            else c = 90;
            res.insert(res.begin(),c);

            if(inp % 26) inp /= 26;
            else inp = inp / 26 - 1;
        }
        return res;
    }
};
