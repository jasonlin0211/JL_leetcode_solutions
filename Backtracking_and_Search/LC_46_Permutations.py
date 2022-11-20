# Written by: Jian-Yuan Lin
# Date: 2022.11.19

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        used = [False] * n
        ans = []
        def dfs(curr, ans):
            if len(curr) == n:
                ans.append(curr[:])
                return 
            for i in range(n):
                if used[i]: continue
                used[i] = True
                curr.append(nums[i])
                dfs(curr, ans)
                used[i] = False
                curr.pop()
        dfs([], ans)
        return ans