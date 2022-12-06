# Written by: Jian-Yuan Lin
# Date: 2022.12.06

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        goal = len(nums) - 1
        
        for i in range(goal-1, -1, -1):
            if i + nums[i] >= goal:
                goal = i
        return goal == 0