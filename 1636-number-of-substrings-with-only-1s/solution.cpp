class Solution {
public:
    int numSub(string s) {
        const long long MOD = 1e9 + 7;
        long long count = 0, sum = 0;
        for(auto x : s){
            if(x == '1') count++;
            else{
                sum = (sum + (count * (count + 1) / 2) % MOD) % MOD;
                count = 0;
            }
        }
        sum = (sum + (count * (count + 1) / 2) % MOD) % MOD;
        return sum;
    }
};
