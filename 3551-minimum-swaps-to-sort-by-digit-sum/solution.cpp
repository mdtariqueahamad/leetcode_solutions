class Solution {
public:
    int digitSum(int x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end(), [&](auto& a, auto& b) {
            int sa = digitSum(a.first);
            int sb = digitSum(b.first);

            if (sa != sb) return sa < sb;
            return a.first < b.first;
        });

        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            pos[v[i].second] = i;
        }

        vector<bool> vis(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            int j = i, len = 0;

            while (!vis[j]) {
                vis[j] = true;
                j = pos[j];
                len++;
            }

            if (len > 1) swaps += len - 1;
        }

        return swaps;
    }
};