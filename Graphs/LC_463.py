class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        visited = set()
        def dfs(grid, row, col, visited):
            # border cases
            if row < 0 or row == m or col < 0 or col == n or grid[row][col] == 0:
                return 1
            if (row, col) in visited:
                return 0
            visited.add((row, col))
            ans = dfs(grid, row+1, col, visited)
            ans += dfs(grid, row-1, col, visited)
            ans += dfs(grid, row, col+1, visited)
            ans += dfs(grid, row, col-1, visited)
            return ans
        for row in range(m):
            for col in range(n):
                if grid[row][col] == 1:
                    return dfs(grid, row, col, visited)