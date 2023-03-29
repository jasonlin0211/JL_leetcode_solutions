class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        max_day = days[-1]
        dp = [0 for i in range(max_day + 1)]
        seen = set(days)
        for d in range(1, max_day + 1):
            if d not in seen:
                dp[d] = dp[d-1]
            else:
                dp[d] = dp[d-1] + costs[0]
                dp[d] = min(dp[d], dp[max(0, d - 7)] + costs[1])
                dp[d] = min(dp[d], dp[max(0, d - 30)] + costs[2])
                
        return dp[max_day]