# Written by: Jian-Yuan Lin
# Date: 2022.12.06

class Solution:
    def reverseBits(self, n: int) -> int:
        # Neetcode solution using & and |
        ans = 0
        for i in range(32):
            bit = (n >> i) & 1 # get the ith bit if it's 1
            ans = ans | (bit << (31-i)) # change the result's bit(reverse order)
        
        return ans
        
        
        """
        # original bit at i will be at 31 - i
        ans , power = 0, 31
        while n:
            ans += (n & 1) << power
            n >>= 1
            power -= 1
        return ans
        
        """