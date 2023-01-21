# Written by: Jian-Yuan Lin
# Date: 2023.01.19

class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        # classical backtracking problem!
        seen = set()
        ans = []

        def dfs(i, curr):
            if i == len(nums):
                if len(curr) >= 2:
                    seen.add(tuple(curr))
                return
            if len(curr) == 0 or nums[i] >= curr[-1]:
                curr.append(nums[i])
                dfs(i+1, curr)
                curr.pop()
            dfs(i+1, curr)
        dfs(0, [])
        for item in seen:
            ans.append(list(item))
        return ans