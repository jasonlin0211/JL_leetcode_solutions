# Written by: Jian-Yuan Lin
# Date: 2022.12.06

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0
        for i in range(1, amount+1):
            for c in coins:
                if i >= c:
                    dp[i] = min(dp[i], dp[i-c] + 1)
        
        return dp[amount] if dp[amount] != float('inf') else -1