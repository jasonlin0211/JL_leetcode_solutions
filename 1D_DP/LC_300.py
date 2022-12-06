# Written by: Jian-Yuan Lin
# Date: 2022.12.06

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # O(n^2) for DP way and O(nlogn) for binary search way
        # use binary search to find every component's to be inserted position
        def lower_bound(nums, val):
            l, r = 0, len(nums)
            while l < r:
                mid = l + (r-l)//2
                if nums[mid] >= val:
                    r = mid
                else:
                    l = mid + 1
            return l
        
        LIS = []
        for num in nums:
            pos = lower_bound(LIS, num)
            if pos == len(LIS):
                LIS.append(num)
            else:
                LIS[pos] = num
        return len(LIS)

        """
        # text book solution, now TLE for latest test case = =
        n = len(nums)
        dp = [1] * n
        for i in range(1, n):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], 1 + dp[j])
        return max(dp)

        """
        