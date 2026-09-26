// LeetCode Problem 0121: Best Time to Buy and Sell Stock
// Difficulty: Easy
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Language: cpp

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