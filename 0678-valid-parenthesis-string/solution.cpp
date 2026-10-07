class Solution {
public:
    bool checkValidString(string s) {
        
        int count = 0, par = 0;

        for(char c: s){
            if('(' == c) {
                par++;
                count++;
            }
            else if('*' == c) {
                count++;
                par--;
            }
            else{
                par--;
                count--;
            }

            if(count < 0) return false;

            par = max(0, par);
        }

        return !par;
    }
};