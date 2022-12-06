# Written by: Jian-Yuan Lin
# Date: 2022.12.06

class Solution:
    def getSum(self, a: int, b: int) -> int:
        # this is very diffcult one!
        # a + b = (a xor b) xor (a & b << 1), first part is addition in every digit
        # second part is the carry, we stop until carry is 0
        
        def add(a, b):
            if not a or not b:
                return a or b
            return add(a ^ b, (a & b) << 1)
        
        # now consider the negative cases
        # we always assume a < 0, b > 0
        if a * b < 0: # one element is negative
            if a > 0:
                return self.getSum(b, a) # just reverse the order
            if add(~a, 1) == b: # this means -a == b!
                return 0
            # most tricky one!
            if add(~a, 1) < b: # -a < b
                return add(~add(add(~a, 1), add(~b, 1)),1) # -add((-a), (-b))
        
        return add(a,b)