class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &e: edges)
            adj[e[0]].push_back({e[1], e[2]});

        vector<long long> ans(n, -1);
        vector<int> cnt(n, 0);
        vector<unordered_set<int>> seen(n);

        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;

        auto activate = [&](int u, long long t) {

            ans[u] = t;

            for(auto &[v, d]: adj[u])
                    pq.push({t+d, v, u});
        };

        activate(0, 0);

        while(!pq.empty()) {
            auto [t, v, u] = pq.top();
            pq.pop();

            if(ans[v] != -1) continue;
            if(!seen[v].insert(u).second) continue;

            cnt[v]++;
            if(cnt[v] >= requiredSignals[v])
                activate(v, t);
        }

        return ans;
    }
};
