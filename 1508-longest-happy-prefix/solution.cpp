class Solution {
    static const long long MOD = 1000000007;
    typedef long long ll;
public:
    string longestPrefix(string s) {
        
        ll prefHash = 0, suffHash = 0, n = s.size(), power = 1;
        int idx = 0;

        for(int i = 0; i < n-1; i++) {

            int x = n-i-1; char pr = s[i], sf = s[x];

            prefHash = (prefHash * 100 + ll(pr - 'a' + 1)) % MOD;
            suffHash = (ll(sf - 'a' + 1) * power + suffHash) % MOD;

            power = (power * 100) % MOD;

            if(prefHash == suffHash) {
                idx = i+1;
            }
        }

        return s.substr(0, idx);
    }
};
