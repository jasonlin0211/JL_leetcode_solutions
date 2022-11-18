# Written by: Jian-Yuan Lin
# Date: 2022.11.17

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        ans = 0

        def dfs(grid, row, col):
            if row < 0 or row == m or col < 0 or col == n or grid[row][col] != 1:
                return 0
            grid[row][col] = -1
            l = dfs(grid, row, col-1)
            r = dfs(grid, row, col+1)
            t = dfs(grid, row-1, col)
            b = dfs(grid, row+1, col)
            return 1 + l + r + t + b

        for row in range(m):
            for col in range(n):
                if grid[row][col] == 1:
                    ans = max(ans, dfs(grid, row, col))
        return ans