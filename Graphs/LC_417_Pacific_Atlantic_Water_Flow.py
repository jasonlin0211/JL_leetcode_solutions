# Written by: Jian-Yuan Lin
# Date: 2022.11.18

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m, n = len(heights), len(heights[0])
        pac_seen, atl_seen = set(), set()

        def dfs(row, col, prev, seen):
            if row < 0 or row == m or col < 0 or col == n or (row, col) in seen or heights[row][col] < prev:
                return
            seen.add((row, col))
            dfs(row+1, col, heights[row][col], seen)
            dfs(row-1, col, heights[row][col], seen)
            dfs(row, col+1, heights[row][col], seen)
            dfs(row, col-1, heights[row][col], seen)
            return 
        for row in range(m):
            dfs(row, 0, -1, pac_seen)
            dfs(row, n-1, -1, atl_seen)
        
        for col in range(n):
            dfs(0, col, -1, pac_seen)
            dfs(m-1, col, -1, atl_seen)
        
        ans = []
        for row in range(m):
            for col in range(n):
                if (row, col) in pac_seen and (row, col) in atl_seen:
                    ans.append([row, col])
        return ans