# Written by: Jian-Yuan Lin
# Date: 2022.11.17

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # tricky problem!
        if not nums:
            return 0
        nums_set = set(nums)
        ans = 1

        for num in nums_set:
            if num - 1 not in nums_set:
                curlen = 0
                while num in nums_set:
                    num += 1
                    curlen += 1
                ans = max(ans, curlen)
        return ans