# Written by: Jian-Yuan Lin
# Date: 2022.12.06

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ans = nums[0]
        prev_min, prev_max = nums[0], nums[0]
        n = len(nums)
        for i in range(1, n):
            temp_max = max(nums[i], prev_max * nums[i], prev_min * nums[i])
            prev_min = min(nums[i], prev_max * nums[i], prev_min * nums[i])
            prev_max = temp_max
            ans = max(ans, prev_max)
        
        return ans

        
        
        """
        # need to record the max and min result from previous iteration
        n = len(nums)
        dp_max, dp_min = [0] * n, [0] * n
        dp_max[0] = nums[0]
        dp_min[0] = nums[0]

        for i in range(1, n):
            max_val = max(nums[i] * dp_max[i-1], nums[i] * dp_min[i-1], nums[i])
            min_val = min(nums[i] * dp_max[i-1], nums[i] * dp_min[i-1], nums[i])
            dp_max[i] = max_val
            dp_min[i] = min_val
        return max(max(dp_max), max(dp_min))
        """
        