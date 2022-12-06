# Written by: Jian-Yuan Lin
# Date: 2022.12.05

# to lazy to write the O(1) space solution, do it when I am more available
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m, n = len(matrix), len(matrix[0])
        to_delete_row, to_delete_col = [], []
    
        for row in range(m):
            for col in range(n):
                if matrix[row][col] == 0:
                    to_delete_row.append(row)
                    to_delete_col.append(col)
        
        # delete row-wise
        for row in to_delete_row:
            for idx in range(n):
                matrix[row][idx] = 0
        
        # delete col-wise
        for col in to_delete_col:
            for idx in range(m):
                matrix[idx][col] = 0