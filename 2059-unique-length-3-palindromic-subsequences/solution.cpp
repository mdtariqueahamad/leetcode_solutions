class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int ans = 0;
        for(char ch = 'a'; ch <= 'z'; ch++){
            int L = -1, R = -1;
            for(int i = 0; i < n; i++){
                if(s[i] == ch){
                    L = i;
                    break;
                }
            }
            for(int i = n - 1; i >= 0; i--){
                if(s[i] == ch){
                    R = i;
                    break;
                }
            }

            if(L != -1 && R != -1 && R - L >= 2){
                bool seen[26] = {0};
                for(int i = L + 1; i < R; i++){
                    seen[s[i] - 'a'] = true;
                }

                for(int k = 0; k < 26; k++){
                    if(seen[k]) ans++;
                }
            }
        }

        return ans;
    }
};

