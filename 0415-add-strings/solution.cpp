class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        string s;
        for(int i = num1.size()-1, j = num2.size()-1; i >= 0 || j >= 0; i--, j--){
            int n1 = (i >= 0)? (num1[i] - '0')  : 0;
            int n2 = (j >= 0)? (num2[j] - '0')  : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            sum %= 10;
            s = to_string(sum) + s;
        }
        if(carry)
        s = to_string(carry) + s;
        return s;
    }
};
