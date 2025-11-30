class Solution {
public:
    string toHex(unsigned int num) {
        string res;
        if(!num) return "0";
        while(num){
            int x = num % 16;
            char c = x < 10 ? '0' + x : 'a' + x - 10;
            res = c + res;
            num /= 16;
        }
        return res;
    }
};
