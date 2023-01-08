# Written by: Jian-Yuan Lin
# Date: 2023.01.07

class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        num_neg, num_zeros = 0, 0
        for num in nums:
            if num < 0:
                num_neg += 1
            if num == 0:
                num_zeros += 1
        return max(num_neg, len(nums) - num_neg - num_zeros)