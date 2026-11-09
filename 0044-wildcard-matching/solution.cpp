class Solution {
    vector<vector<int>> dp;
public:
    bool solve(string &s, string &p, int si = 0, int pi = 0) {
        
        if(pi == p.size()) return si == s.size();
        if(dp[si][pi] != -1) return dp[si][pi];

        if(pi < p.size() && p[pi] == '*') {

            bool not_ast = solve(s, p, si, pi+1);
            bool take_ast = si < s.size() && solve(s, p, si+1, pi);
        
            return dp[si][pi] = not_ast || take_ast;
        }
        
        bool cmp = si != s.size() && (p[pi] == s[si] || p[pi] == '?');
        return dp[si][pi] = cmp && solve(s, p, si+1, pi+1);
    }


    bool isMatch(string &s, string p) {

        string pat;
        for(char c : p) {
            if(c == '*' && !pat.empty() && pat.back() == '*')
                continue;

            pat.push_back(c);
        }

        dp.assign(s.size()+1, vector<int>(pat.size()+1, -1));

        return solve(s, pat);
    }
};
