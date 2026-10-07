class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int depth = 0, par = 0;

        for(char c: s){
            if('(' == c) {
                depth++;
            } else {
                if(0 == depth) {
                    par++;
                } else {
                    depth--;
                }
            }
        }

        return par+depth;
    }
};