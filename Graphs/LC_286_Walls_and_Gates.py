# Written by: Jian-Yuan Lin
# Date: 2022.11.18

class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        m, n = len(rooms), len(rooms[0])
        q = collections.deque()
        block = set()
        visited = set()
        for row in range(m):
            for col in range(n):
                if rooms[row][col] == 0:
                    q.append((row, col))
                    visited.add((row, col))
                elif rooms[row][col] == -1:
                    block.add((row, col))
        
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        steps = 0
        while q:
            size = len(q)
            for _ in range(size):
                cur_row, cur_col = q.popleft()
                visited.add((cur_row, cur_col))
                rooms[cur_row][cur_col] = steps
                for dr, dc in dirs:
                    nxt_row, nxt_col = cur_row + dr, cur_col + dc
                    if nxt_row < 0 or nxt_row == m or nxt_col < 0 or nxt_col == n or (nxt_row, nxt_col) in block or (nxt_row, nxt_col) in visited:
                        continue
                    q.append((nxt_row, nxt_col))
                    visited.add((nxt_row, nxt_col))
            steps += 1 