class Solution {
public:
    int func(string s, int idx, bool st, int &neg, long long res){
        if(s.size() == idx) return res;
        if(s[idx] == '-'){
            if(st || neg != -1) return res;
            neg = true;
            return func(s, idx+1, st, neg, res);
        }
        if(s[idx] == '+'){
            if(st || neg != -1) return res;
            neg = 0;
            return func(s, idx+1, st, neg, res);
        }
        if(s[idx] == ' '){
            if(st || neg != -1) return res;
            return func(s, idx+1, st, neg, res);
        }
        if(s[idx] < '0' || s[idx] > '9') return res;
        res = res * 10 + (s[idx] - '0');
        st = true;
        if(res > INT_MAX){
            if(neg == 1){
                neg = -1;
                return INT_MIN;
            }
            return INT_MAX;
        }
        return func(s, idx+1, st, neg, res);
    }

    int myAtoi(string s) {
        int neg = -1;
        int res = func(s, 0, false, neg, 0);
        return neg == 1 ? -res : res;
    }
};
