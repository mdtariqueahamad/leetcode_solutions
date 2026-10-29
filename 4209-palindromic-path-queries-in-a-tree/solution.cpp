template <class T, int V, int E>
class Adj {
private:
    struct Edge { int e; T v; };
    int adj[V];
    Edge edges[E];
    int __edgeCnt = 0;
public:
    class Iterator {
        Adj<T, V, E>::Edge *edges;
        int e;
    public:
        Iterator(Adj<T, V, E>::Edge *edges, int e): edges(edges), e(e) {}
        void operator++() { e = edges[e].e; }
        T& operator*() { return edges[e].v; }
        T* operator->() { return &(edges[e].v); }
        bool notEnd() { return e >= 0; }
    };

    Adj() { clear(); }
    void clear() {
        __edgeCnt = 0;
        memset(adj, 0xff, sizeof(adj));
    }
    void push(int u, T v) {
        edges[__edgeCnt].v = v;
        edges[__edgeCnt].e = adj[u];
        adj[u] = __edgeCnt++;
    }

    Iterator begin(int u) { return Iterator(edges, adj[u]); }
};

template <class T, size_t N>
class MyStack {
private:
    T cont[N];
    int __end;
public:
    MyStack() { clear(); }
    void clear() { __end = 0; }
    void push(T v) { cont[__end++] = v; }
    void pop() { --__end; }
    T& top() { return cont[__end-1]; }
    size_t size() const { return __end; }
    bool nonempty() const { return __end; }
};

class Solution {
private:
    static inline Adj<int, 50000, 100000> adj;
    static inline MyStack<tuple<int, int, int, bool>, 50000> stk;
    static inline int bit[50002];
    static inline int din[50000], dout[50000], dfn2id[50001];
    static inline int depth[50000];
    static inline int anc[16][50000];
    static inline mt19937 gen{181639597};
    void bitBuild(const string &s) {
        int N = s.size() + 1;
        memset(bit+1, 0x00, sizeof(bit[0]) * N);
        for (int i = 0; i < N-1; ++i) {
            int mask = 1 << s[i] - 'a';
            bit[din[i]] ^= mask;
            bit[dout[i]] ^= mask;
        }
        for (int i = 1; i < N; ++i) {
            int j = i + (i & -i);
            if (j < N)
                bit[j] ^= bit[i];
        }
    }
    void bitUpdate(int i, int mask, int N) {
        while (i < N) {
            bit[i] ^= mask;
            i += i & -i;
        }
    }
    int bitSearch(int i) {
        int mask = 0;
        while (i > 0) {
            mask ^= bit[i];
            i -= i & -i;
        }
        return mask;
    }
    void buildAnc(int n) {
        for (int p = 1, h = 2; h <= n; ++p, h <<= 1) {
            for (int i = 0; i < n; ++i) {
                int a = anc[p-1][i];
                anc[p][i] = (a >= 0 ? anc[p-1][a] : a);
            }
        }
    }
    int lca(int x, int y) {
        int dx = depth[x], dy = depth[y];
        if (dx > dy) {
            swap(x, y);
            swap(dx, dy);
        }
        if (dx < dy) {
            int d = dy - dx;
            for (int p = 0; d > 0; ++p, d >>= 1)
                if (d & 1)
                    y = anc[p][y];
        }
        if (x == y)
            return x;
        for (int p = 31 - __builtin_clz(dx); p >= 0; -- p) {
            int ax = anc[p][x], ay = anc[p][y];
            if (ax != ay)
                x = ax, y = ay;
        }
        return anc[0][x];
    }
    static int readNum(string::const_iterator &it) {
        int res = 0;
        while (isdigit(*it)) {
            res = res * 10 + (*it - '0');
            ++it;
        }
        return res;
    }
    static int readNum(string::const_iterator &it, string::const_iterator end) {
        int res = 0;
        while (it != end) {
            res = res * 10 + (*it - '0');
            ++it;
        }
        return res;
    }
    void update(int id, char from, char to, int n) {
        int mask = (1 << from - 'a') | (1 << to - 'a');
        bitUpdate(din[id], mask, n+1);
        bitUpdate(dout[id], mask, n+1);
    }
    bool search(int x, int y, const string& s) {
        int mask = bitSearch(din[x]) ^ bitSearch(din[y]) ^ (1 << s[lca(x, y)] - 'a');
        return __builtin_popcount(mask) <= 1;
    }
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string &s, vector<string>& queries) {
        adj.clear();
        for (auto &e: edges) {
            adj.push(e[0], e[1]);
            adj.push(e[1], e[0]);
        }
        const int root = gen() % n;
        while (!queries.empty() && queries.back()[0] == 'u')
            queries.pop_back();
        if (queries.empty())
            return {};

        int qi;
        for (qi = 0; qi < queries.size() && queries[qi][0] == 'u'; ++qi) {
            const auto& q = queries[qi];
            auto it = q.cbegin() + 7;
            int id = readNum(it, q.cend() - 2);
            char ch = *(it + 1);
            s[id] = ch;
        }

        // dfs
        int t = 1;
        stk.clear();
        stk.push({root, -1, 0, 0});
        while (stk.nonempty()) {
            auto [node, pred, d, phase] = stk.top();
            stk.pop();
            if (phase) {
                dout[node] = t;
                continue;
            }
            stk.push({node, pred, d, 1});
            depth[node] = d;
            dfn2id[t] = node;
            din[node] = t++;
            anc[0][node] = pred;
            for (auto it = adj.begin(node); it.notEnd(); ++it) {
                int succ = *it;
                if (succ != pred) {
                    stk.push({succ, node, d+1, 0});
                }
            }
        }

        bitBuild(s);
        buildAnc(n);

        vector<bool> res;
        res.reserve(queries.size() - qi);
        for (const auto &q: span{queries.begin() + qi, queries.end()}) {
            if (q[0] == 'u') {
                auto it = q.cbegin() + 7;
                int id = readNum(it, q.cend() - 2);
                char ch = *(it + 1);
                if (s[id] != ch) {
                    update(id, s[id], ch, n);
                    s[id] = ch;
                }
            }
            else {
                auto it = q.cbegin() + 6;
                int x = readNum(it);
                int y = readNum(++it, q.cend());
                res.push_back(search(x, y, s));
            }
        }

        return res;
    }
};
