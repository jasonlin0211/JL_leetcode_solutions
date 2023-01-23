# Written by: Jian-Yuan Lin
# Date: 2023.01.22

class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        # 2D difference array + prefix sum
        diff = [[0] * (n+1) for _ in range(n+1)]
        for r1, c1, r2, c2 in queries:
            diff[r1][c1] += 1
            diff[r1][c2+1] -= 1
            diff[r2+1][c1] -= 1
            diff[r2+1][c2+1] += 1
        
        ans = [[0] * (n+1) for _ in range(n+1)]
        for i in range(n):
            for j in range(n):
                # 2D prefix sum 
                ans[i+1][j+1] = ans[i+1][j] + ans[i][j+1] - ans[i][j] + diff[i][j]
        #print(ans)
        #del ans[0]
        #for row in ans:
        #    del row[0]
        result = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                result[i][j] = ans[i+1][j+1]
        return result

        '''
        1D difference array + prefix sum
        ans = [[0] * n for _ in range(n)]
        for r1, c1, r2, c2 in queries:
            for r in range(r1, r2+1):
                ans[r][c1] += 1
                # avoid out of bound
                if c2 + 1 < n:
                    ans[r][c2+1] -= 1
        # do the prefix sum
        for row in ans:
            for j in range(1, n):
                row[j] += row[j-1]
        return ans
        '''