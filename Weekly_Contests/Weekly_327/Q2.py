# Written by: Jian-Yuan Lin
# Date: 2023.01.07

class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        maxheap = []
        for num in nums:
            heapq.heappush(maxheap, -num)
        
        ans = 0
        for _ in range(k):
            val = -heapq.heappop(maxheap)
            ans += val
            heapq.heappush(maxheap, -ceil(val/3))
        return ans