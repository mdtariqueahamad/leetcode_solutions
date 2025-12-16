class Solution{
public:
    int characterReplacement(string s, int k) {
        int mx = 0;
        for(char c = 'A'; c <= 'Z'; c++){
        int i = 0, j = 0, zero = 0;
        for( ; j < s.size(); j++){
            if(!(s[j]==c)) zero++;
            if(zero > k){
                while(zero > k){
                    if(!(s[i]==c)) zero--;
                    i++;
                }
            }
            mx = max(mx, j-i+1);
            }
        }
        return mx;
    }
};
