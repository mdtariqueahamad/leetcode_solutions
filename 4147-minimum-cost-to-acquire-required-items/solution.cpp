class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        if(cost1+cost2 <= costBoth) {
            return 1LL * cost1*need1 + 1LL * cost2*need2;
        }

        int mn = min(need1, need2);
        long long ans = 1LL * mn * costBoth;
        need1 -= mn, need2 -= mn;

        if(cost1 < costBoth) ans += 1LL * cost1 * need1;
        else ans += 1LL * costBoth * need1;
        
        if(cost2 < costBoth) ans += 1LL * cost2 * need2;
        else ans += 1LL * costBoth * need2;

        return ans;
    }
};
