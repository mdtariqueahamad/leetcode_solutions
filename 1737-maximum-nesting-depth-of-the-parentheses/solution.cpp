class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        stack<char> st;
        for(char c: s){
            if(c == '(') st.push(c);
            else if(c == ')') st.pop();
            int x = st.size();
            ans = max(ans, x);
        }

        return ans;
    }
};
