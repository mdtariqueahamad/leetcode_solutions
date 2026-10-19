class Solution {
    int MOD = 1e9 + 7;

    vector<vector<int>> PT;

    int solve(vector<int> &nums) {
        int n = nums.size();
        if(3 > n) return 1;

        vector<int> left_Arr, right_Arr;
        int root = nums[0];

        for(int i = 1; i < n; i++) {
            if(nums[i] > root) right_Arr.push_back(nums[i]);
            else left_Arr.push_back(nums[i]);
        }

        int left = solve(left_Arr) % MOD;
        int right = solve(right_Arr) % MOD;

        int count = PT[n-1][right_Arr.size()] % MOD;

        return (((1LL * count*left) % MOD) * right) % MOD;
    }
public:
    int numOfWays(vector<int>& nums) {

        int n = nums.size();

        PT.resize(n+1);

        for(int i = 0; i <= n; i++) {
            PT[i].resize(i+1);

            PT[i][0] = PT[i][i] = 1;

            for(int j = 1; j < i; j++) {
                PT[i][j] = (PT[i-1][j] + PT[i-1][j-1]) % MOD;
            }
        }

        return solve(nums)-1;
    }
};