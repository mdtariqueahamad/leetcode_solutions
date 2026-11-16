class Solution {
public:
    string digitSum(string s, int k) {
        
        if(s.size() <= k) return s;
        
        top:
        
        string ans;
        int idx = 0;
        
        while(idx < s.size()) {
            int num = 0;
            
            for(int i = 0; idx < s.size() && i < k; i++, idx++) {
                num += (s[idx] - '0');
            }
            
            ans += to_string(num);
        }
        
        if(ans.size() > k) {
            s = ans;
            goto top;
        }
        
        return ans;
    }
};
