# Written by: Jian-Yuan Lin
# Date: 2022.11.17

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        for idx, a in enumerate(nums):
            if idx != 0 and a == nums[idx-1]:
                continue
            l, r = idx + 1, len(nums)-1
            while l < r:
                total = a + nums[l] + nums[r]
                if total > 0:
                    r -= 1
                elif total < 0:
                    l += 1
                else:
                    ans.append([a, nums[l], nums[r]])
                    l += 1
                    while l < r and nums[l] == nums[l-1]:
                        l += 1
        return ans