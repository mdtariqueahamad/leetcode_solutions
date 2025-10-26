class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int Profit = 0;

        for (int price : prices) {
            if (price < buy)
                buy = price;
            else if (price - buy > Profit)
                Profit = price - buy;
        }

        return Profit;
    }
};
