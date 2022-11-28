// Written by: Jian-Yuan Lin
// Date: 2022.11.28

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev_min = INT_MAX;
        int max_profit = INT_MIN;
        for (int price: prices){
            prev_min = min(price, prev_min);
            int cur_profit = price - prev_min;
            max_profit = max(cur_profit, max_profit);
        }
        return max_profit;
    }
};