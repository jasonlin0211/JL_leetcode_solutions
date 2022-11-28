# Written by: Jian-Yuan Lin
# Date: 2022.11.20

class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums)
        if len(nums) == 1:
            return nums[0]
        
        if nums[l] < nums[r-1]:
            return nums[l]

        while l < r:
            mid = l + (r-l)//2
            if nums[mid-1] > nums[mid]:
                return nums[mid]
            # 0 - mid is sorted, pivot point must be on the right side
            if nums[0] < nums[mid]:
                l = mid + 1
            else:
                r = mid
        