class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for(char c: s)
            if('*' == c) st.pop();
            else st.push(c);

        s.clear();
        while(!st.empty()){
            s += st.top();
            st.pop();
        }

        reverse(s.begin(), s.end());  // O(n)
        return s;
    }
};
