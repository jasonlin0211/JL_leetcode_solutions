# Written by: Jian-Yuan Lin
# Date: 2022.11.20

class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        m, n = len(maze), len(maze[0])
        start_row, start_col = entrance[0], entrance[1]
        q = collections.deque()
        q.append((start_row, start_col))
        seen = set()
        seen.add((start_row, start_col))
        steps = 0

        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        found = 0
        while q:
            size = len(q)
            for _ in range(size):
                cur_row, cur_col = q.popleft()
                if cur_row == 0 or cur_col == 0 or cur_row == m-1 or cur_col == n-1:
                    if cur_row == start_row and cur_col == start_col:
                        found = 0
                    else:
                        found = 1
                if found:
                    return steps
                for dr, dc in dirs:
                    nxt_row, nxt_col = cur_row + dr, cur_col + dc
                    if nxt_row < 0 or nxt_row == m or nxt_col < 0 or nxt_col == n or (nxt_row, nxt_col) in seen or maze[nxt_row][nxt_col] == '+':
                        continue
                    seen.add((nxt_row, nxt_col))
                    q.append((nxt_row, nxt_col))
            steps += 1
        return -1