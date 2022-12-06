// Written by: Jian-Yuan Lin
// Date: 2022.12.06

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for (int val = 1; val <= amount; val++){
            for(int coin: coins){
                if (val - coin >= 0 && dp[val-coin] != INT_MAX){
                    dp[val] = min(dp[val], dp[val-coin] + 1);
                }
            }
        }
        if (dp[amount] == INT_MAX){
            return -1;
        }
        return dp[amount];

    }
};