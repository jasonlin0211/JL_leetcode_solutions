# Written by: Jian-Yuan Lin
# Date: 2022.12.06

class Solution:
    def hammingWeight(self, n: int) -> int:
        # bit manipulation: use n & (n-1)
        # example:
        #   100001
        # & 100000
        # ------
        #   100000
        # & 011111
        #----------
        #   000000
        ans = 0
        
        while n:
            ans += 1
            n = n & (n-1) # eleminate the least significant 1 bit to 0!
        return ans
        """
        brute force using mask
        ans = 0
        mask = 1
        for _ in range(32):
            if n & mask != 0:
                ans += 1
            mask = mask << 1
        return ans
        """
        