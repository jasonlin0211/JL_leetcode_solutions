# Written by: Jian-Yuan Lin
# Date: 2022.11.19

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        ans = []
        def dfs(nums, t, start, curr, ans):
            if t == 0:
                ans.append(curr[:])
                return
            if t < 0:
                return
            for i in range(start, len(nums)):
                if i != start and nums[i] == nums[i-1]: continue
                curr.append(nums[i])
                dfs(nums, t - nums[i], i+1, curr, ans)
                curr.pop()
                
        dfs(candidates, target, 0, [], ans)

        return ans