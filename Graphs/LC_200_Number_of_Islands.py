# Written by: Jian-Yuan Lin
# Date: 2022.11.17

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        ans = 0

        def dfs(grid, row, col):
            if row < 0 or row == m or col < 0 or col == n or grid[row][col] != "1":
                return
            grid[row][col] = "X"
            dfs(grid, row+1, col)
            dfs(grid, row-1, col)
            dfs(grid, row, col+1)
            dfs(grid, row, col-1)
        
        for row in range(m):
            for col in range(n):
                if grid[row][col] == "1":
                    ans += 1
                    dfs(grid, row, col)
        return ans