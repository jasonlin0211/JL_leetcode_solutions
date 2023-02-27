class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1
        # otherwise, you can go back and forth to wait for the time goes by
        dist = {}
        for row in range(m):
            for col in range(n):
                dist[(row, col)] = float('inf')
        # dist[(i, j)] 's parity must be the same with (i + j)
        dist[(0, 0)] = 0
        minheap = []
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        heapq.heappush(minheap, (0, 0, 0)) # (cur_time, cur_row, cur_col)
        while minheap:
            cur_time, cur_row, cur_col = heapq.heappop(minheap)
            if cur_row == m-1 and cur_col == n-1:
                return cur_time
            for dr, dc in dirs:
                nxt_row, nxt_col = cur_row + dr, cur_col + dc
                if nxt_row < 0 or nxt_row == m or nxt_col < 0 or nxt_col == n:
                    continue
                nxt_time = max(cur_time+1, grid[nxt_row][nxt_col])
                nxt_time += (nxt_time - nxt_row - nxt_col) % 2 # if parity not the same, we need to add one!
                if nxt_time < dist[(nxt_row, nxt_col)]:
                    dist[(nxt_row, nxt_col)] = nxt_time
                    heapq.heappush(minheap, (nxt_time, nxt_row, nxt_col))
        return -1