#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSetBits(vector<int>& a, int k) {
        int n = a.size(), m = n - k + 1, id = 0;
        unique_ptr<uint32_t[]> sf(new uint32_t[k]), xs(new uint32_t[m]);
        uint32_t av = ~0u, ov = 0, dm[31];
        fill(dm, dm + 31, ~0u);
        for (int l = 0; l + k <= n; l += k) {
            sf[k - 1] = a[l + k - 1];
            for (int j = k - 2; j >= 0; j--) sf[j] = sf[j + 1] & a[l + j];
            uint32_t pr = ~0u;
            for (int j = 0; j < k && l + j + k <= n; j++) {
                uint32_t v = sf[j] & pr;
                if (!v) return -1;
                av &= v;
                ov |= v;
                xs[id++] = v;
                if (l + k + j < n) pr &= a[l + k + j];
            }
        }
        if (av) return 1;
        for (int i = 0; i < m; i++) {
            if (i && xs[i] == xs[i - 1]) continue;
            for (uint32_t t = xs[i]; t; t &= t - 1) dm[__builtin_ctz(t)] &= xs[i];
        }
        uint32_t kp = 0, mp[31]{}, t0[2048]{}, t1[1024]{}, t2[1024]{};
        int b = 0;
        for (int p = 0; p < 31; p++) {
            if (!(ov >> p & 1)) continue;
            uint32_t d = dm[p];
            bool dr = 0;
            for (int q = 0; q < 31; q++)
                if (q != p && (d >> q & 1) && (!(dm[q] >> p & 1) || q < p)) dr = 1;
            if (!dr) kp |= 1u << p;
        }
        for (int p = 0; p < 31; p++) if (kp >> p & 1) mp[p] = 1u << b++;
        for (int i = 1; i < 2048; i++) t0[i] = t0[i & (i - 1)] | mp[__builtin_ctz(i)];
        for (int i = 1; i < 1024; i++) {
            int c = __builtin_ctz(i), j = i & (i - 1);
            t1[i] = t1[j] | mp[c + 11];
            t2[i] = t2[j] | mp[c + 21];
        }
        uint64_t pm[7]{};
        for (int i = 0; i < 64; i++) pm[__builtin_popcount(i)] |= 1ULL << i;
        int an = b, D = min(b, 20), W = 1 << max(0, D - 6);
        unique_ptr<uint64_t[]> bs(new uint64_t[W]()), bf(new uint64_t[W]());
        auto f = [&](auto&& sl, uint64_t* p, int d, int c) -> void {
            if (c >= an || (p[0] & 1)) return;
            if (d <= 6) {
                uint64_t w = p[0];
                if (!w) {
                    an = c;
                    return;
                }
                w |= (w & 0x5555555555555555ULL) << 1;
                w |= (w & 0x3333333333333333ULL) << 2;
                w |= (w & 0x0F0F0F0F0F0F0F0FULL) << 4;
                w |= (w & 0x00FF00FF00FF00FFULL) << 8;
                w |= (w & 0x0000FFFF0000FFFFULL) << 16;
                w |= w << 32;
                uint64_t u = ~w;
                for (int r = 6; r >= 0; r--)
                    if (u & pm[r]) {
                        if (c + 6 - r < an) an = c + 6 - r;
                        return;
                    }
                return;
            }
            int h = 1 << (d - 7);
            uint64_t* q = p + h;
            if (q[0] & 1) {
                if (c + 1 < an) sl(sl, p, d - 1, c + 1);
                return;
            }
            uint64_t *nx = bf.get() + h, lo = 0, hi = 0;
            for (int i = 0; i < h; i++) {
                lo |= p[i];
                hi |= q[i];
                nx[i] = p[i] | q[i];
            }
            if (!lo) {
                int v = c + (hi != 0);
                if (v < an) an = v;
                return;
            }
            sl(sl, nx, d - 1, c);
            if (hi && c + 1 < an) sl(sl, p, d - 1, c + 1);
        };
        if (b <= 20) {
            for (int i = 0; i < m; i++) {
                uint32_t v = xs[i], cm = t0[v & 2047] | t1[v >> 11 & 1023] | t2[v >> 21];
                bs[cm >> 6] |= 1ULL << (cm & 63);
            }
            f(f, bs.get(), b, 0);
        } else {
            deque<uint32_t> q(m);
            for (int i = 0; i < m; i++) {
                uint32_t v = xs[i];
                q[i] = t0[v & 2047] | t1[v >> 11 & 1023] | t2[v >> 21];
            }
            sort(q.begin(), q.end());
            q.erase(unique(q.begin(), q.end()), q.end());
            auto g = [&](auto&& sl, const deque<uint32_t>& s, int d, int c) -> void {
                if (c >= an) return;
                if (s.empty()) {
                    an = c;
                    return;
                }
                if (d <= 20) {
                    memset(bs.get(), 0, W * sizeof(uint64_t));
                    for (uint32_t v : s) bs[v >> 6] |= 1ULL << (v & 63);
                    f(f, bs.get(), d, c);
                    return;
                }
                uint32_t hb = 1u << (d - 1);
                deque<uint32_t> lo, hi;
                for (uint32_t v : s)
                    if (v & hb) hi.push_back(v ^ hb);
                    else lo.push_back(v);
                if (lo.empty()) {
                    if (c + 1 < an) an = c + 1;
                    return;
                }
                if (hi.empty()) {
                    sl(sl, lo, d - 1, c);
                    return;
                }
                if (hi[0]) {
                    deque<uint32_t> mg;
                    set_union(lo.begin(), lo.end(), hi.begin(), hi.end(), back_inserter(mg));
                    sl(sl, mg, d - 1, c);
                }
                if (c + 1 < an) sl(sl, lo, d - 1, c + 1);
            };
            g(g, q, b, 0);
        }
        return an;
    }
};
