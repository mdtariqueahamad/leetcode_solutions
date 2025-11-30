class Solution {
public:
    char findTheDifference(string s, string t) {
        int arr[26] = {0};
        for(char c : t)
        arr[c - 'a']++;
        for(char c : s)
        arr[c - 'a']--;

        for(int i = 0; i < 26; i++)
        if(arr[i] == 1) return (char)(i + 'a');

        return '0';
    }
};
