# Written by: Jian-Yuan Lin
# Date: 2022.11.20


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums)

        while l < r:
            mid = l + (r-l)//2
            if nums[mid] == target:
                return mid
            # left part is sorted in ascending order
            if nums[l] < nums[mid]:
                if nums[l] <= target <= nums[mid]:
                    r = mid
                else:
                    l = mid + 1
            # right part is sorted in ascending order
            else:
                if nums[mid] <= target <= nums[r-1]:
                    l = mid + 1
                else:
                    r = mid
        return -1