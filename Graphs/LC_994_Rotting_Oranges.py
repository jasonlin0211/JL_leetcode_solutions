# Written by: Jian-Yuan Lin
# Date: 2022.11.18

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        q = collections.deque()
        fresh = 0
        seen = set()
        for row in range(m):
            for col in range(n):
                if grid[row][col] == 2:
                    q.append((row, col))
                    seen.add((row, col))
                elif grid[row][col] == 1:
                    fresh += 1
        if fresh == 0:
            return 0
        steps = 0
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        
        while q:
            size = len(q)
            for _ in range(size):
                cur_row, cur_col = q.popleft()
                for dr, dc in dirs:
                    nxt_row, nxt_col = cur_row + dr, cur_col + dc
                    if nxt_row < 0 or nxt_row == m or nxt_col < 0 or nxt_col == n or (nxt_row, nxt_col) in seen:
                        continue
                    if grid[nxt_row][nxt_col] == 1:
                        grid[nxt_row][nxt_col] = 2
                        seen.add((nxt_row, nxt_col))
                        q.append((nxt_row, nxt_col))
                        fresh -= 1
                        if fresh == 0:
                            return steps + 1
            steps += 1
        return -1