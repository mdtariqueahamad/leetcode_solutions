class Solution {
public:
    bool closeStrings(string word1, string word2) {

        unordered_set<int> s1(word1.begin(), word1.end());
        unordered_set<int> s2(word2.begin(), word2.end());

        if(s1 != s2) return false;

         vector<int> v1(26), v2(26);

        for(char c: word1)
            v1[c-'a']++;

        for(char c: word2)
            v2[c-'a']++;

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        return v1 == v2;
    }
};