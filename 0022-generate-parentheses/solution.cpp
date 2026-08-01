class Solution {
public:
    void func(int n, int open, int close, string s, vector<string> &st){
        if(n > open) func(n, open + 1, close, s+'(', st);
        if(open > close) func(n, open, close+1, s+')', st);
        if(open == n && close == n){
        st.push_back(s);
        return;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> st;
        func(n, 0, 0, "", st);
        return st;
    }
};
