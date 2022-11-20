# Written by: Jian-Yuan Lin
# Date: 2022.11.19

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        # even cleaner implementation
        ans = []
        n = len(nums)
        def dfs(i, curr):
            if i == n:
                ans.append(curr[:])
                return
            # include
            curr.append(nums[i])
            dfs(i+1, curr)
            # not include
            curr.pop()
            dfs(i+1, curr)
        
        dfs(0, [])
        return ans
        """
        # generate all combinations for the given length
        ans = []
        n = len(nums)
        def dfs(l, nums, start, curr, ans):
            if len(curr) == l:
                ans.append(curr[:])
                return 
            for i in range(start, len(nums)):
                curr.append(nums[i])
                dfs(l, nums, i+1, curr, ans)
                curr.pop()
                
        for l in range(n+1):
            dfs(l, nums, 0, [], ans)
        return ans
        """
        