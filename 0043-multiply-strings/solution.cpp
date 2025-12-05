class Solution {
public:
    string multiply(string num1, string num2){
        string s, z;
        for(int i = num1.size()-1; i >= 0; i--, z += '0'){
            string prod;
            int carry = 0;
            int n1 = num1[i] - '0';
            for(int j = num2.size()-1; j >= 0; j--){
                int pr = n1 * (num2[j] - '0');
                pr += carry;
                carry = pr / 10;
                pr %= 10;
                prod = to_string(pr) + prod;
            }
            if(carry) prod = to_string(carry) + prod;
            prod += z;
            carry = 0;
            string s1;
            for(int k = s.size()-1, l = prod.size()-1; k >= 0 || l >= 0; k--, l--){
                int n1 = (k >= 0) ? s[k] - '0': 0;
                int n2 = (l >= 0) ? prod[l] - '0' : 0;
                int sum = n1 + n2 + carry;
                carry = sum / 10;
                sum %= 10;
                s1 = to_string(sum) + s1;
            }
            if(carry) s1 = to_string(carry) + s1;
            s = s1;
        }
        int i = 0;
        while(s.size()-1 > i && s[i] == '0'){
            i++;
        }
        s = s.substr(i);
        return s;
    }
};
