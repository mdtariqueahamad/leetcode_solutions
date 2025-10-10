class Solution {
public:
    int titleToNumber(string inp) {
        int res = 0;
        for (int i = 0; i < inp.size(); ++i){
            res += (inp[i] - 64) * pow(26, inp.size() - 1 - i);
        }
        return res;
    }
};
