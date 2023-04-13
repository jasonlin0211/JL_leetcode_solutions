class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        # mark all 1s to 0s from the boundary
        def mark_boundary(grid, row, col):
            if row < 0 or row == m or col < 0 or col == n or grid[row][col] == 0:
                return
            grid[row][col] = 0
            mark_boundary(grid, row+1, col)
            mark_boundary(grid, row-1, col)
            mark_boundary(grid, row, col+1)
            mark_boundary(grid, row, col-1)
        
        
        for row in range(m):
            if grid[row][0] == 1:
                mark_boundary(grid, row, 0)
            if grid[row][n-1] == 1:
                mark_boundary(grid, row, n-1)
        
        for col in range(n):
            if grid[0][col] == 1:
                mark_boundary(grid, 0, col)
            if grid[m-1][col] == 1:
                mark_boundary(grid, m-1, col)
        ans = 0        
        # find the remaining 1s in the grid
        for row in range(m):
            ans += sum(grid[row])
        return ans
        """
        def dfs(grid, row, col):
            if row < 0 or row == m or col < 0 or col == n or grid[row][col] == 0:
                return 0
            grid[row][col] = 0
            t = dfs(grid, row-1, col)
            d = dfs(grid, row+1, col)
            r = dfs(grid, row, col+1)
            l = dfs(grid, row, col-1)
            return 1 + t + d + r + l
        
        for row in range(m):
            for col in range(n):
                if grid[row][col] == 1:
                    ans += dfs(grid, row, col)
        return ans
        
        """
        