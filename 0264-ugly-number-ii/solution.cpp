class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> st = {1};

        int ans = *st.begin();
        while(n--) {
            int temp = *st.begin();
            st.erase(temp);
            st.insert(1LL*2*temp);
            st.insert(1LL*3*temp);
            st.insert(1LL*5*temp);
            ans = temp;
        }

        return ans;
    }
};
