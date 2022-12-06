# Written by: Jian-Yuan Lin
# Date: 2022.12.05

class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        def rob_1(nums):
            
            rob1, rob2 = 0, 0
            n = len(nums)
            #[rob1, rob2, n, n+1....]
            for i in range(n):
                temp = max(rob1 + nums[i], rob2)
                rob1 = rob2
                rob2 = temp
            return rob2
        
        return max(rob_1(nums[:-1]), rob_1(nums[1:]))