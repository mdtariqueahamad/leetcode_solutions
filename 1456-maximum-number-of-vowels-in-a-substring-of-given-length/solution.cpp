class Solution {
public:
    char check_vowel(char c){
        if(c == 'a'|| c == 'e' || c == 'i' || c == 'o' || c == 'u') return '1';
        return '0';
    }
    int maxVowels(string s, int k) {
        for(int i = 0; i < s.size(); i++){
            s[i] = check_vowel(s[i]);
        }

        int i = 0;
        int sum = 0, ans = 0;
        for(; i < k; i++) sum += (s[i] - '0');

        ans = sum;

        for(int j = 0; i<s.size(); i++, j++){
            sum -= (s[j] - '0');
            sum += (s[i] - '0');
            ans = max(ans, sum);
            if(ans == k) return ans;
        }

        return ans;
    }
};