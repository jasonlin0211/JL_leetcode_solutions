# Written by: Jian-Yuan Lin
# Date: 2022.11.19

class Solution:
    def unequalTriplets(self, nums: List[int]) -> int:
        ans = []
        def dfs(nums, start, curr, ans):
            if len(curr) == 3:
                ans.append(list(curr))
                return
            for i in range(start, len(nums)):
                if curr and nums[i] in curr:
                    continue
                curr.add(nums[i])
                dfs(nums, i+1, curr, ans)
                curr.remove(nums[i])
        curr = set()
        dfs(nums, 0, curr, ans)
        return len(ans)