# Written by: Jian-Yuan Lin
# Date: 2023.01.07

class Solution:
    def xorBeauty(self, nums: List[int]) -> int:
        # ((a | b) & c) xor ((b | a) & c) -- > 0, so we only need to care about (a | a) & c
        # (a | a) & c = a & c, (a & c) xor (c & a) -> 0, so we only need to care about (a | a) & a -> a
        # so the answer will be the xor of every num in the nums
        ans = nums[0]
        for i in range(1, len(nums)):
            ans ^= nums[i]
        return ans