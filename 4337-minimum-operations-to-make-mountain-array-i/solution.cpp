const int INF = 1e9;
class Solution {

    int n, m;
    int memo[1005][2005][2];
    
    int solve(int i, int lim, int up, vector<int> &nums) {

        if(n == i) return up? INF: 0;

        int &res = memo[i][lim][up];
        if(res != -1) return res;
        res = INF;
        
        if(up) {
            if(lim + 1 > m) return res;
            int v = lim+1;
            int cost = abs(nums[i]-v);

            res = min(res, cost + solve(i+1, v, 1, nums));

            if(i > 0 && i < n-1)
                res = min(res, cost + solve(i+1, v, 0, nums));

            res = min(res, solve(i, v, 1, nums));
        } else {
            if(lim-1 < 1) return res;
            int v = lim - 1;

            res = min(res, abs(nums[i] - v) + solve(i+1, v, 0, nums));
            res = min(res, solve(i, v, 0, nums));
        }

        return res = min(res, INF);
    }
public:
    int minOperations(vector<int>& nums) {

        if(nums.size() < 3) return -1;
        
        n = nums.size();
        m = *max_element(nums.begin(), nums.end()) + n + 1;
        memset(memo, -1, sizeof(memo));

        int ans = solve(0, 0, 1, nums);
        return ans < INF? ans: -1;
    }
};
