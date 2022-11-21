# Written by: Jian-Yuan Lin
# Date: 2022.11.20


class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        
        ans = nums[0]
        while l <= r:
            # everything is sorted, leftmost must be min!
            if nums[l] < nums[r]:
                ans = min(nums[l], ans)
                break
            mid = l + (r-l)//2
            ans = min(ans, nums[mid])
            if nums[l] <= nums[mid]:
                l = mid + 1
            else:
                r = mid - 1
        return ans