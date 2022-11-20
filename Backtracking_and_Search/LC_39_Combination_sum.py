# Written by: Jian-Yuan Lin
# Date: 2022.11.19

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []

        def dfs(nums, start, target, curr, ans):
            if target == 0:
                ans.append(curr[:])
                return 
            elif target < 0:
                return 
            for i in range(start, len(nums)):
                curr.append(nums[i])
                dfs(nums, i, target - nums[i], curr, ans)
                curr.pop()
        dfs(candidates, 0, target, [], ans)
        return ans