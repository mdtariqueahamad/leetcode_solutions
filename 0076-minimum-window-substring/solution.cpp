class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpp;
        for (char c : t)
            mpp[c]++;
        int l = 0, r = 0, count = 0, minl = INT_MAX, index = -1;
        while (r < s.size()) {
            mpp[s[r]]--;
            count += (mpp[s[r]] >= 0);

            while (count == t.size()) {
                if (minl > r - l + 1) {
                    minl = r - l + 1;
                    index = l;
                }

                mpp[s[l]]++;
                count -= (mpp[s[l]] > 0);
                l++;
            }

            r++;
        }
        
        return (index == -1) ? "" : s.substr(index, minl);
    }
};
