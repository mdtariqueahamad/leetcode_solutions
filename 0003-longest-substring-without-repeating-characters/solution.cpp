class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m=0;
        string s1 = "";
        for (int i = 0; i < s.size(); i++) {
            size_t pos = s1.find(s[i]);

            if (pos != string::npos) {
                // erase up to duplicate
                s1.erase(0, pos + 1);
            }

            s1.push_back(s[i]);
            m = max(m, (int)s1.size());  // update max after each step
        }
        return m;
    }
};
