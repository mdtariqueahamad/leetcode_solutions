class Solution {
public:
    int myAtoi(string s) {
        long long res = 0;
        int i = 0, n = s.size();
        int sign = 1;

        // Skip leading spaces
        while(i < n && s[i] == ' ') i++;

        // Optional sign
        if(i < n && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-') sign = -1;
            i++;
        }

        // Parse digits
        while(i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check for overflow
            if(res > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            res = res * 10 + digit;
            i++;
        }

        return (int)(res * sign);
    }
};
