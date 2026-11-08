class Solution {
    vector<int> dp;

public:
    int helper(string &s, int idx) {
        if(idx == s.size()) return 1;
        if(s[idx] == '0') return 0;

        if(dp[idx] != -1) return dp[idx];

        int ways = helper(s, idx + 1);

        if(idx + 1 < s.size()) {
            int num = stoi(s.substr(idx, 2));

            if(num <= 26)
                ways += helper(s, idx + 2);
        }

        return dp[idx] = ways;
    }

    int numDecodings(string s) {
        dp.assign(s.size(), -1);
        return helper(s, 0);
    }
};
