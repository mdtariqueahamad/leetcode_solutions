class Solution {
public:
    int nextGreaterElement(int m) {
        
        string s = to_string(m);
        int n = s.size(), idx = -1, mn = n-1;
        for(int i = n-1; i > 0; i--)
            if(s[i] > s[i-1]) {
                idx = i-1;
                break;
            }

        if(-1 == idx) return -1;

        for(int i = n-1; i > idx; i--)
            if(s[idx] < s[i]) {
                swap(s[idx], s[i]);
                break;
            }

        string temp = s.substr(idx+1);

        sort(temp.begin(), temp.end());

        s = s.substr(0, idx+1) + temp;

        long long ans = stoll(s);
        if(ans > INT_MAX) return -1;
        return ans;
    }
};
