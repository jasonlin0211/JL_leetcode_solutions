# Written by: Jian-Yuan Lin
# Date: 2022.12.05

class Solution:
    def rob(self, nums: List[int]) -> int:
        # space optimized version
        rob1, rob2 = 0, 0
        n = len(nums)
        #[rob1, rob2, n, n+1....]
        for i in range(n):
            temp = max(rob1 + nums[i], rob2)
            rob1 = rob2
            rob2 = temp
        return rob2

        """
        n = len(nums)
        if n == 1:
            return nums[0]
        dp = [0] * (n+1)
        dp[1] = nums[0]
        for i in range(2, n+1):
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1])
        return dp[n]
        """