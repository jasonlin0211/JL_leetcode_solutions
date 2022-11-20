# Written by: Jian-Yuan Lin
# Date: 2022.11.19

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])

        def dfs(board, row, col, idx):
            if idx == len(word):
                return True
            if row < 0 or row == m or col < 0 or col == n or board[row][col] != word[idx]:
                return False
            temp = board[row][col]
            board[row][col] = "#"
            t = dfs(board, row-1, col, idx+1)
            b = dfs(board, row+1, col, idx+1)
            l = dfs(board, row, col-1, idx+1)
            r = dfs(board, row, col+1, idx+1)
            board[row][col] = temp
            return t or b or l or r


        for row in range(m):
            for col in range(n):
                if dfs(board, row, col, 0):
                    return True
        return False