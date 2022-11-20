# Written by: Jian-Yuan Lin
# Date: 2022.11.19

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        used_col, used_diag, used_anti_diag = set(), set(), set()
        ans = []
        
        def dfs(row, curr, ans):
            if row == n:
                ans.append(curr[:])
                return
            for col in range(n):
                diag_idx = row-col
                anti_diag_idx = row + col
                if col in used_col or diag_idx in used_diag or anti_diag_idx in used_anti_diag:
                    continue
                used_col.add(col)
                used_diag.add(diag_idx)
                used_anti_diag.add(anti_diag_idx)
                temp = "." * col + "Q" + "." * (n-col-1)
                curr.append(temp)
                dfs(row+1, curr, ans)
                curr.pop()
                used_col.remove(col)
                used_diag.remove(diag_idx)
                used_anti_diag.remove(anti_diag_idx)

        dfs(0, [], ans)
        return ans