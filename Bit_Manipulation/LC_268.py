# Written by: Jian-Yuan Lin
# Date: 2022.12.06

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        # using summation
        n = len(nums)
        ans = n
        for i in range(n):
            ans += (i - nums[i])
        
        return ans
        
        
        
        """
        # bit manipulation
        missing = len(nums)
        for idx, num in enumerate(nums):
            missing ^= (idx ^ num) # if idx and num matching--> 0, a ^ 0 = a
        return missing
        
        
        """
        
        
        """
        # hashset
        seen = set(nums)
        n = len(nums)
        for i in range(n+1):
            if i not in seen:
                return i
        
        """
        