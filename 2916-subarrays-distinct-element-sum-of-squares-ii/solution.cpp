class Solution {
    static const int MOD = 1e9 + 7;
    vector<long long> sum, sq, lz;

    void apply(int o, int l, int r, long long x) {
        long long len = r - l + 1;
        sq[o] = (sq[o] + 2 * x % MOD * sum[o] + len * x % MOD * x) % MOD;
        sum[o] = (sum[o] + len * x) % MOD;
        lz[o] = (lz[o] + x) % MOD;
    }

    void push(int o, int l, int r) {
        if (lz[o]) {
            int m = (l + r) / 2;
            apply(2 * o, l, m, lz[o]);
            apply(2 * o + 1, m + 1, r, lz[o]);
            lz[o] = 0;
        }
    }

    void update(int o, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            apply(o, l, r, 1);
            return;
        }
        push(o, l, r);
        int m = (l + r) / 2;
        if (ql <= m) update(2 * o, l, m, ql, qr);
        if (qr > m)  update(2 * o + 1, m + 1, r, ql, qr);
        sum[o] = (sum[2 * o] + sum[2 * o + 1]) % MOD;
        sq[o]  = (sq[2 * o] + sq[2 * o + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lz.assign(4 * n, 0);

        unordered_map<int, int> last;
        long long ans = 0;

        for (int j = 0; j < n; j++) {
            int prev = last.count(nums[j]) ? last[nums[j]] : -1;
            update(1, 0, n - 1, prev + 1, j);  // +1 to d[i] for i in (prev, j]
            last[nums[j]] = j;
            ans = (ans + sq[1]) % MOD;         // sum of d[i]^2 over all starts
        }
        return ans;
    }
};