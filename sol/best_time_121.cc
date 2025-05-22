
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 1) return 0;
        int min_price = prices[0];
        int max_profit = 0;
        for (auto price: prices) {
            int profit = price - min_price;
            max_profit = max(max_profit, profit);
            min_price = min(min_price, price);
        }
        return max_profit;
    }
};