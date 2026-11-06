class Solution {
    vector<vector<int>> dp = vector<vector<int>>(21, vector<int>(21, -1));
public:
    bool isMatch(string &s, string &p, int si = 0, int pi = 0) {
        
        if(pi == p.size()) return si == s.size();

        if(dp[si][pi] != -1) return dp[si][pi];

        bool cmp = si != s.size() && (p[pi] == s[si] || p[pi] == '.');

        if(pi+1 < p.size() && p[pi+1] == '*') {

            bool not_ast = isMatch(s, p, si, pi+2);
            bool take_ast = cmp && isMatch(s, p, si+1, pi);
        
            return dp[si][pi] = not_ast || take_ast;
        }
        
        return dp[si][pi] = cmp && isMatch(s, p, si+1, pi+1);
    }
};
