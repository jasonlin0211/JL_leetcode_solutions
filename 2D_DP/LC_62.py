# Written by: Jian-Yuan Lin
# Date: 2022.12.06

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0] * (n+1) for _ in range(m+1)]
        dp[1][1] = 1
        for row in range(1, m+1):
            for col in range(1, n+1):
                dp[row][col] += dp[row-1][col] + dp[row][col-1]
        return dp[m][n]
        """
        dp = [[0] * n for _ in range(m)]
        dp[0][0] = 1
        for row in range(m):
            for col in range(n):
                if row == 0 and col == 0:
                    continue
                if row == 0:
                    dp[row][col] += dp[row][col-1]
                elif col == 0:
                    dp[row][col] += dp[row-1][col]
                else:
                    dp[row][col] += dp[row-1][col] + dp[row][col-1]
        return dp[m-1][n-1]
        """