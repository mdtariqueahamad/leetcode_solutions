class Solution {
    int rec(string s, long long num, int idx, int sign, bool check){
        if(idx == s.size()) return sign * num;
        if(s[idx] > '9') return sign * num;
        else if(s[idx] < '0'){
            if(check) return sign * num;
            else{
                if(s[idx] == '-')
                return rec(s, num, idx+1, -1, true);
                else{
                    if(s[idx] == ' ')
                    return rec(s, num, idx+1, sign, check);
                    else if(s[idx] == '+')
                    return rec(s, num, idx+1, sign, true);
                    else return sign * num;
                }
            }
        }

        num = num * 10 + (s[idx] - '0');
        check = true;

        if(num * sign >= INT_MAX) return INT_MAX;
        else if(num * sign < INT_MIN) return INT_MIN;
        return rec(s, num, idx+1, sign, check);
    }
public:
    int myAtoi(string s){
        return rec(s, 0, 0, 1, false);
    }
};
