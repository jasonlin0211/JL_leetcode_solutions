# Written by: Jian-Yuan Lin
# Date: 2022.12.06

class Solution:
    def countBits(self, n: int) -> List[int]:
        # O(n) solution using DP
        # even more understandable solution by Neetcode
        dp = [0] * (n+1)
        offset = 1
        for i in range(1, n+1):
            # advance to the new most significant bit
            if offset * 2 == i:
                offset = i
            dp[i] = 1 + dp[i-offset]
        return dp
        
        
        """
        O(nlogn) solution 
        
        def count(n):
            ans = 0
        
            while n:
                ans += 1
                n = n & (n-1) # eleminate the least significant 1 bit to 0!
            return ans
        ans = []
        for i in range(n+1):
            ans.append(count(i))
        return ans
        """
        