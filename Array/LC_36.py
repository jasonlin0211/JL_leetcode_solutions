# Written by: Jian-Yuan Lin
# Date: 2022.11.17

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        row_set = [set() for i in range(9)]
        col_set = [set() for i in range(9)]
        block_set = [set() for i in range(9)]
        
        for row in range(9):
            for col in range(9):
                curval = board[row][col]
                if curval == ".":
                    continue
                if curval in row_set[row] or curval in col_set[col] or curval in block_set[3*(row//3) + (col//3)]:
                    return False
                row_set[row].add(curval)
                col_set[col].add(curval)
                block_set[3*(row//3) + (col//3)].add(curval)
        return True