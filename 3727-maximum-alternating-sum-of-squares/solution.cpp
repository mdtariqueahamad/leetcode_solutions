class Solution {
    static bool fp(int a, int b) {
        return abs(a) > abs(b);
    }

public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), fp);

        int *low = nums.data(), *high = nums.data() + nums.size() - 1;

        long long ans = 0;

        while (low <= high) {
            if (low == high) {
                ans += 1LL * *low * *low;
                break;
            }

            ans += 1LL * *low * *low;
            low++;

            ans -= 1LL * *high * *high;
            high--;
        }

        return ans;
    }
};