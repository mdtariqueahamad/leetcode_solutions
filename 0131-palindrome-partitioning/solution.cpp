class Solution {
    vector<vector<string>> ans;
    vector<string> temp;

    bool isP(string &s) {
        int idx = 0, n = s.size()-1;

        for(int i = 0; i <= n/2; i++) {
            if(s[i] != s[n-i]) return false;
        }
        return true;
    }
public:

    void solve(string &s, int idx, int n, string str) {

        if(n == s.size()) {
            ans.push_back(temp);
            return;
        }

        if(idx == s.size()) return;

        str += s[idx];

        if(isP(str)) {
            temp.push_back(str);
            n += str.size();
            solve(s, idx+1, n, "");
            temp.pop_back();
            n -= str.size();
        }

        solve(s, idx+1, n, str);
    }

    vector<vector<string>> partition(string s) {

        solve(s, 0, 0, "");

        return ans;
    }
};
