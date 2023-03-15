class Solution:
    def splitNum(self, num: int) -> int:
        digits = []
        while num:
            digits.append(num % 10)
            num //= 10
        digits.sort()
        n1, n2 = [], []
        for i in range(len(digits)):
            if i % 2 == 0:
                n1.append(digits[i])
            else:
                n2.append(digits[i])
        
        def cal(nums):
            res = 0
            for n in nums:
                res = res * 10 + n
            return res
            
        return cal(n1) + cal(n2)