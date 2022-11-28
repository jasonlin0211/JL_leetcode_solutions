# Written by: Jian-Yuan Lin
# Date: 2022.11.27

class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        ans = [[0] * n for _ in range(m)]
        val_row, val_col = [0] * m, [0] * n
        
        for row in range(m):
            val_row[row] = 2 * sum(grid[row]) - m
        
        for col in range(n):
            col_total = 0
            for row in range(m):
                col_total += grid[row][col]
            val_col[col] = 2 * col_total - n
        
        for row in range(m):
            for col in range(n):
                ans[row][col] = val_row[row] + val_col[col]
        return ans