class Solution {
public:
    int minInsertions(string s) {
        int depth = 0, ans = 0;

        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if('(' == c) {
                if(depth&1) {
                    depth--;
                    ans++;
                }
                depth += 2;
            } else {
                if(depth) depth--;
                else {
                    int temp = 1;
                    i++;
                    while(i < s.size() && ')' == s[i]) {
                        temp++;
                        i++;
                    }
                    if(i < s.size())
                    i--;
                    ans += (temp&1)? (temp+3)/2: temp/2;
                }
            }
        }

        return ans+depth;
    }
};