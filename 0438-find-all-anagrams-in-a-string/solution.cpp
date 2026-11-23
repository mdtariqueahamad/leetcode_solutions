class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        if(s.size() < p.size()) return {};

        vector<int> freq(26, 0);
        for(char c: p)
            freq[c - 'a']++;

        vector<int> ans;

        for(int i = 0; i <= s.size() - p.size(); i++) {

            if(!freq[s[i] - 'a']) continue;

            vector<int> cf(26, 0);

            for(int j = i; j < i + p.size(); j++)
                cf[s[j] - 'a']++;

            if(cf == freq)
                ans.push_back(i);
        }

        return ans;
    }
};
