class Solution {
public:
    int maxPoints(vector<vector<int>> &nums) {

        int ans = 0, n = nums.size();
        if(n < 3) return n;

        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++) {
                int dx = nums[i][0] - nums[j][0],
                dy = nums[i][1] - nums[j][1],
                count = 2;
                for(int k = 0; k < n; k++)
                    if(k != i && k != j) {
                        int dx_ = nums[k][0] - nums[i][0],
                        dy_ = nums[k][1] - nums[i][1];
                        if(dy * dx_ == dy_ * dx) count++;
                    }
                ans = max(count, ans);
            }

        return ans;
    }
};
