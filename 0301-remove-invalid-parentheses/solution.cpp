class Solution {
public:
    vector<string> ans;

    void solve(string &s, int i, int bal, int l, int r,  string &curr){
        if (i == s.size()) {
            if (bal == 0 && l == 0 && r == 0)
                ans.push_back(curr);
            return;
        }

        char c = s[i];

        if ('(' == c && l)
            solve(s, i + 1, bal, l - 1, r, curr);

        if (')' == c && r)
            solve(s, i + 1, bal, l, r - 1, curr);

        if (')' != c) {
            curr += c;
            solve(s, i + 1, bal + (c == '('), l, r, curr);
            curr.pop_back();
        }
        else if (bal) {
            curr += c;
            solve(s, i + 1, bal - 1, l, r, curr);
            curr.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        
        int right = 0, left = 0;

        for(char c: s)
            if('(' == c) left++;
            else if(')' == c)
                !left ? right++: left--;
        
        string curr;
        solve(s, 0, 0, left, right, curr);

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};