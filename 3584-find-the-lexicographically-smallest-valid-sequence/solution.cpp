class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> suf(n + 1, 0);

        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1];

            if (j >= 0 && word1[i] == word2[j]) {
                suf[i]++;
                j--;
            }
        }

        vector<int> ans;

        int j2 = 0;
        bool used = false;

        for (int i = 0; i < n && j2 < m; i++) {

            if (word1[i] == word2[j2]) {
                ans.push_back(i);
                j2++;
            }
            else if (!used) {
                int need = m - j2 - 1;

                if (suf[i + 1] >= need) {
                    ans.push_back(i);
                    j2++;
                    used = true;
                }
            }
        }

        if (j2 == m)
            return ans;

        return {};
    }
};
