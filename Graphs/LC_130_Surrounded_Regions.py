# Written by: Jian-Yuan Lin
# Date: 2022.11.18

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # detect the "O" attached from the side first, then do DFS to mark all "O" to "X"
        # then eventually flip all of the "O" from the first step
        m, n = len(board), len(board[0])
        side = set()
        
        def find_side(board, row, col, seen):
            if row < 0 or row == m or col < 0 or col == n or (row, col) in seen or board[row][col] != "O":
                return
            seen.add((row, col))
            find_side(board, row+1, col, seen)
            find_side(board, row-1, col, seen)
            find_side(board, row, col+1, seen)
            find_side(board, row, col-1, seen)
        
        def dfs(board, row, col):
            if row < 0 or row == m or col < 0 or col == n or board[row][col] != "O":
                return
            board[row][col] = "X"
            dfs(board, row+1, col)
            dfs(board, row-1, col)
            dfs(board, row, col+1)
            dfs(board, row, col-1)
        
        for row in range(m):
            find_side(board, row, 0, side)
            find_side(board, row, n-1, side)
        
        for col in range(n):
            find_side(board, 0, col, side)
            find_side(board, m-1, col, side)
        
        for row in range(m):
            for col in range(n):
                if board[row][col] == "O":
                    dfs(board, row, col)
        
        for row in range(m):
            for col in range(n):
                if (row, col) in side:
                    board[row][col] = "O"