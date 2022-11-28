# Written by: Jian-Yuan Lin
# Date: 2022.11.28

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        prev_min, ans = prices[0], 0
        for i in range(1, len(prices)):
            price = prices[i]
            ans = max(price - prev_min, ans)
            prev_min = min(price, prev_min)
        return ans