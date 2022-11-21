# Written by: Jian-Yuan Lin
# Date: 2022.11.20


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # this is actually a complicated problem, use the example case to understand!
        # [4 5 6 7 0 1 2] --> left and right portion
        # use mid and nums[l] to check which part is the middle in
        # left: check right if val is greater than mid or val is smaller than nums[l]
        #       else check left
        # right: check left if val is smaller than mid or val is greater than nums[r]
        #      else check right
        # not found, return -1
        
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = l + (r-l)//2
            if nums[mid] == target:
                return mid
            # mid is in the left portion
            elif nums[mid] >= nums[l]:
                if nums[mid] < target or nums[l] > target:
                    l = mid + 1
                else:
                    r = mid - 1
            # mid is in the right portion
            else:
                if nums[mid] > target or nums[r] < target:
                    r = mid - 1
                else:
                    l = mid + 1

        return -1