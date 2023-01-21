# Written by: Jian-Yuan Lin
# Date: 2023.01.17

class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        total = sum(nums)

        def find_max_subarray_sum(nums):
            # kadane algo
            ans = -float('inf')
            cur = -float('inf')
            for num in nums:
                cur = num + max(cur, 0)
                ans = max(ans, cur)
            return ans

        def find_min_subarray_sum(nums):
            # kadane algo
            ans = float('inf')
            cur = float('inf')
            for num in nums:
                cur = num + min(cur, 0)
                ans = min(ans, cur)
            return ans

        max_subarray_sum = find_max_subarray_sum(nums)
        min_subarray_sum = find_min_subarray_sum(nums)

        if max_subarray_sum > 0:
            return max(max_subarray_sum, total - min_subarray_sum)
        else:
            return max_subarray_sum