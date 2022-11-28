# Written by: Jian-Yuan Lin
# Date: 2022.11.27

class Solution:
    def bestClosingTime(self, customers: str) -> int:
        n = len(customers)
        right_Y, left_N = [0] * (n+1), [0] * (n+1)
        total_Y, total_N = 0, 0
        
        for i in range(n):
            if customers[i] == 'Y':
                total_Y += 1
            else:
                total_N += 1
        
        right_Y[0] = total_Y
        left_N[n] = total_N
        for i in range(1, n+1):
            if customers[i-1] == 'Y':
                right_Y[i] = right_Y[i-1] - 1
                left_N[i] = left_N[i-1]
            else:
                right_Y[i] = right_Y[i-1]
                left_N[i] = left_N[i-1] + 1
        #print(right_Y)
        #print(left_N)
        ans = [0] * (n+1)
        for i in range(n+1):
            ans[i] = right_Y[i] + left_N[i]
        minval = min(ans)
        for i in range(n+1):
            if ans[i] == minval:
                return i
            
            