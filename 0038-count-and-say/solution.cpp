class Solution {
public:
    string countAndSay(int n) {

        if(n == 1) return "1";

        string s = "11";

        for(int i = 3; i <= n; i++) {

            string temp;

            for(int j = 0; j < s.size()-1; j++) {
                int cnt = 1;
                while(j < s.size()-1 && s[j] == s[j+1]){
                    cnt++;
                    j++;
                }
                temp += to_string(cnt) + s[j];
            }
            if(s[s.size()-2] != s[s.size()-1]) temp += string("1") + s[s.size()-1];

            s = temp;
        }

        return s;
    }
};
