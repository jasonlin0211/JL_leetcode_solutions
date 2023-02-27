# Date: 2023.02.09
# Written by Jian-Yuan Lin

class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        # this problem is actually quite tricky, we need to do the reverse way, start BFS from the land
        # we want to find how many steps we can do in the BFS iteration process
        # note we need to start steps = -1
        n = len(grid)
        q = collections.deque()
        seen = set()
        for row in range(n):
            for col in range(n):
                if grid[row][col] == 1:
                    q.append((row, col))
                    seen.add((row, col))
        steps = -1
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        while q:
            size = len(q)
            for _ in range(size):
                cur_row, cur_col = q.popleft()
                for dr, dc in dirs:
                    nxt_row, nxt_col = cur_row + dr, cur_col + dc
                    if nxt_row < 0 or nxt_row == n or nxt_col < 0 or nxt_col == n or (nxt_row, nxt_col) in seen or grid[nxt_row][nxt_col] == 1:
                        continue
                    q.append((nxt_row, nxt_col))
                    seen.add((nxt_row, nxt_col))
            steps += 1
        
        return steps if steps != 0 else -1