# Written by: Jian-Yuan Lin
# Date: 2022.12.06

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        # textbook solution
        m, n = len(text1), len(text2)
        dp = [[0] * (n+1) for _ in range(m+1)]
        for row in range(1, m+1):
            for col in range(1, n+1):
                if text1[row-1] == text2[col-1]:
                    dp[row][col] = max(dp[row-1][col-1] + 1, dp[row][col])
                else:
                    dp[row][col] = max(dp[row-1][col], dp[row][col-1])
        return dp[m][n]