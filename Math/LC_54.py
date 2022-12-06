# Written by: Jian-Yuan Lin
# Date: 2022.12.06

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        # Neetcode's code is more concise
        res = []
        left, right = 0, len(matrix[0])
        top, bottom = 0, len(matrix)

        while left < right and top < bottom:
            # get every i in the top row
            for i in range(left, right):
                res.append(matrix[top][i])
            top += 1
            # get every i in the right col
            for i in range(top, bottom):
                res.append(matrix[i][right - 1])
            right -= 1
            if not (left < right and top < bottom):
                break
            # get every i in the bottom row
            for i in range(right - 1, left - 1, -1):
                res.append(matrix[bottom - 1][i])
            bottom -= 1
            # get every i in the left col
            for i in range(bottom - 1, top - 1, -1):
                res.append(matrix[i][left])
            left += 1

        return res
        """
        m, n = len(matrix), len(matrix[0])
        total = m * n
        ans = []
        l, r, t, b = 0, n-1, 0, m-1
        
        while l <= r and t <= b:
            # top traversal
            for idx in range(l, r+1):
                ans.append(matrix[t][idx])
                if len(ans) == total:
                    return ans
            t += 1
            # right traversal
            for idx in range(t, b+1):
                ans.append(matrix[idx][r])
                if len(ans) == total:
                    return ans
            r -= 1
            # bottom traversal
            for idx in range(r, l-1, -1):
                ans.append(matrix[b][idx])
                if len(ans) == total:
                    return ans
            b -= 1
            # left traversal
            for idx in range(b, t-1, -1):
                ans.append(matrix[idx][l])
                if len(ans) == total:
                    return ans
            l += 1
            #print(l,r, t, b)
        return ans
        """