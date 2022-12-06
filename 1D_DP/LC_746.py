# Written by: Jian-Yuan Lin
# Date: 2022.12.04

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [0] * (n+1)
        for i in range(2, n+1):
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2])
        return dp[n]
        
        """
        top down is easy to make mistake...
        mem = {}
        mem[0] = 0
        mem[1] = 0
        n = len(cost)
        def dp(i):
            if i in mem:
                return mem[i]
            mem[i] = min(dp(i-1) + cost[i-1], dp(i-2) + cost[i-2])
            return mem[i]
        return dp(n)
        """
        