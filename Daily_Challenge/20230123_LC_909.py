# Written by: Jian-Yuan Lin
# Date: 2023.01.23

class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        # construct the mapping for ladders
        ladders = {}
        flip = False
        val = 1
        for row in range(n-1, -1, -1):
            # no flip, left to right
            if not flip:
                for col in range(n):
                    if board[row][col] != -1:
                        ladders[val] = board[row][col]
                    val += 1
                flip = True
            else:
                for col in range(n-1, -1, -1):
                    if board[row][col] != -1:
                        ladders[val] = board[row][col]
                    val += 1
                flip = False
        # then standard BFS
        q = collections.deque()
        q.append(1)
        seen = set()
        seen.add(1)
        steps = 0
        while q:
            size = len(q)
            for _ in range(size):
                cur = q.popleft()
                if cur == n ** 2:
                    return steps
                options = [i for i in range(cur+1, min(cur+6, n**2) + 1)]
                for nxt in options:
                    if nxt in ladders:
                        nxt = ladders[nxt]
                    if nxt not in seen:
                        seen.add(nxt)
                        q.append(nxt)
            steps += 1
        return -1