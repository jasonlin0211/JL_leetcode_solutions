class Solution:
    def ways(self, pizza: List[str], k: int) -> int:
        # this is too difficult....
        m, n = len(pizza), len(pizza[0])
        kMod = 10**9 + 7
        A = [[0] * (n+1) for _ in range(m+1)]
        for row in range(m):
            for col in range(n):
                val = 0
                if pizza[row][col] == 'A':
                    val = 1
                A[row+1][col+1] = A[row+1][col] + A[row][col+1] + val - A[row][col]
        #print(A)
        def hasApple(row1, col1, row2, col2, A):
            if (A[row2+1][col2+1] - A[row2+1][col1] - A[row1][col2+1] + A[row1][col1]) > 0:
                return 1
            return 0
        
        mem = {}

        def dp(row, col, k):
            if k == 0:
                mem[(row, col, k)] = hasApple(row, col, m-1, n-1, A)
                return mem[(row, col, k)]
            if (row, col, k) in mem:
                return mem[(row, col, k)]
            ans = 0
            # cut horizontally 
            for row1 in range(row, m):
                ans = (ans + hasApple(row, col, row1, n-1, A) * dp(row1 + 1, col, k-1)) % kMod
            # cut vertically
            for col1 in range(col, n):
                ans = (ans + hasApple(row, col, m-1, col1, A) * dp(row, col1+1, k-1)) % kMod
            mem[(row, col, k)] = ans
            return mem[(row, col, k)]

        return dp(0, 0, k-1)