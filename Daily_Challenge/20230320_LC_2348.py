class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        i, n = 0, len(nums)
        ans = 0
        while i < n:
            if nums[i] == 0:
                j = i + 1
                while j < n and nums[j] == 0:
                    j += 1
                l = j - i + 1
                ans += l * (l-1) // 2
                i = j
            i += 1
        return ans