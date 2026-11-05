class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        vector<int> l(prices.size(), 0), r(prices.size(), 0);

        int mn = prices[0];

        for(int i = 1; i < prices.size(); i++) {
            l[i] = max(l[i-1], prices[i] - mn);
            mn = min(mn, prices[i]);
        }

        int mx = prices[prices.size()-1];
        for(int i = prices.size()-2; i >= 0; i--) {
            r[i] = max(r[i+1], mx - prices[i]);
            mx = max(mx, prices[i]);
        }

        int ans = 0;

        for(int i = 0; i < prices.size(); i++)
            ans = max(ans, l[i]+r[i]);

        return ans;
    }
};
