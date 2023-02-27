class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        minheap, heapmax = [], 0
        # O(n logm, m is the max val in nums)
        for n in nums:
            temp = n
            # even, we can divide it by 2
            while n % 2 == 0:
                n //= 2
            '''
            basically we want to store the range of the specific num can vary
            so we try to store (minval, maxval) 
            1. 4 -> 2 -> 1, once we get to 1, we can only get it to 2, but we still need to remember original number 4
            2. 1 -> 2, since odd number can be multiply by 2, we also need to store 2
            '''
            minheap.append((n, max(temp, 2 * n))) # (minval, maxval)
            heapmax = max(heapmax, n)
        
        ans = float('inf')
        # O(nlogm * logn)
        heapq.heapify(minheap)

        while len(minheap) == len(nums):
            n, maxval = heapq.heappop(minheap)
            ans = min(ans, heapmax - n)
            if n < maxval:
                heapq.heappush(minheap, (2*n, maxval))
                heapmax = max(heapmax, 2*n)
        return ans