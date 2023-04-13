class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        m, n = len(grid1), len(grid1[0])
        visited = set()

        def dfs(row, col):
            if row < 0 or row == m or col < 0 or col == n or grid2[row][col] == 0 or (row, col) in visited:
                return True
            result = True
            visited.add((row, col))
            if grid1[row][col] == 0:
                result = False
            result = dfs(row+1, col) and result
            result = dfs(row-1, col) and result
            result = dfs(row, col+1) and result
            result = dfs(row, col-1) and result
            return result

        ans = 0
        for row in range(m):
            for col in range(n):
                if grid2[row][col] and (row, col) not in visited and dfs(row, col):
                    ans += 1
        return ans