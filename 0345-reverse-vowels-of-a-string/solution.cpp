class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);
        return 'a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c;
    }
    string reverseVowels(string s) {
        int low = 0, high = s.size()-1;

        while(low < high){
            while(low < high && !isVowel(s[low])) low++;
            while(low < high && !isVowel(s[high])) high--;
            swap(s[low++], s[high--]);
        }
        return s;
    }
};