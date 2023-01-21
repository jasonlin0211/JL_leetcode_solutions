# Written by: Jian-Yuan Lin
# Date: 2023.01.18

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = collections.defaultdict(int)
        count[0] = 1
        total, ans = 0, 0
        for num in nums:
            total += num
            ans += count[total - k]
            count[total] += 1
        return ans