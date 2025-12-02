class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c: s){
            if(c == '(' || c == '{' || c == '[')
                st.push(c);
            else{
                if(st.empty()) return false;
                if((st.top() != c - 2) && (st.top() != c - 1)) return false;
                else st.pop();
            }
        }
        return st.empty();
    }
};
