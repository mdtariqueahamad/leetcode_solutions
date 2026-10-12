class Solution {
    vector<array<int,10>> ch;
    vector<int> term, pos;
    long long ans = 0;

    vector<int> dfs(int u) {
        vector<vector<int>> g;
        for (int v : ch[u]) if (v) g.push_back(dfs(v));
        int m = g.size();

        vector<vector<long long>> c(m, vector<long long>(m));
        for (int a = 0; a < m; a++)
            for (int b = 0; b < m; b++)
                if (a != b)
                    for (int x : g[a])
                        c[a][b] += lower_bound(g[b].begin(), g[b].end(), x) - g[b].begin();

        vector<long long> dp(1 << m, LLONG_MAX);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << m); mask++)
            for (int k = 0; k < m; k++) if (!(mask >> k & 1)) {
                long long add = 0;
                for (int j = 0; j < m; j++) if (mask >> j & 1) add += c[j][k];
                dp[mask | 1 << k] = min(dp[mask | 1 << k], dp[mask] + add);
            }
        ans += dp.back();

        vector<int> vals;
        for (auto& s : g) vals.insert(vals.end(), s.begin(), s.end());
        sort(vals.begin(), vals.end());
        if (term[u] >= 0) {
            auto it = lower_bound(vals.begin(), vals.end(), pos[term[u]]);
            ans += it - vals.begin();
            vals.insert(it, pos[term[u]]);
        }
        return vals;
    }

public:
    int minInversions(vector<string>& words, vector<int>& target) {
        int n = words.size();
        pos.assign(n, 0);
        for (int i = 0; i < n; i++) pos[target[i]] = i;

        auto toravelmis = make_pair(words, target);

        ch.push_back({}); term.push_back(-1);
        for (int i = 0; i < n; i++) {
            int u = 0;
            for (char x : toravelmis.first[i]) {
                int c = x - 'a';
                if (!ch[u][c]) {
                    ch[u][c] = ch.size();
                    ch.push_back({}); term.push_back(-1);
                }
                u = ch[u][c];
            }
            term[u] = i;
        }
        dfs(0);
        return ans;
    }
};