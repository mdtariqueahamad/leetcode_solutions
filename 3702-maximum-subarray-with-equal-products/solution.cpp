
class Solution {
public:
    int maxLength(vector<int>& nums) {

        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            long long Lcm = nums[i],
            Gcd = nums[i],
            prod = nums[i];

            for(int j = i+1; j < nums.size(); j++) {

                Lcm = lcm(Lcm, (long long)nums[j]);
                Gcd = gcd(Gcd, (long long)nums[j]);
                prod *= nums[j];

                if(Gcd * Lcm < prod) break;

                if(Gcd * Lcm == prod)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};
