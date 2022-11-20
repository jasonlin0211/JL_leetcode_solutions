# Written by: Jian-Yuan Lin
# Date: 2022.11.19

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        n = len(nums)

        def dfs(l, nums, start, curr, ans):
            if len(curr) == l:
                ans.append(curr[:])
                return
            for i in range(start, n):
                if i != start and nums[i] == nums[i-1]:
                    continue
                curr.append(nums[i])
                dfs(l, nums, i+1, curr, ans)
                curr.pop()

        for l in range(n+1):
            dfs(l, nums, 0, [], ans)
        return ans