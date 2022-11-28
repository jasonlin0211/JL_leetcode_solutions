# Written by: Jian-Yuan Lin
# Date: 2022.11.27

class Solution:
    def pivotInteger(self, n: int) -> int:
        for x in range(1, n+1):
            if x * (x+1) == (n+x) * (n-x+1):
                return x
        
        return -1