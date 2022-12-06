# Written by: Jian-Yuan Lin
# Date: 2022.12.05

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # try quick select
        target = len(nums) - k
        
        
        def quickselect(nums, l, r):
            pivot, p = nums[r], l
            for idx in range(l, r):
                # before p are the values smaller than pivot
                if nums[idx] <= pivot:
                    nums[p], nums[idx] = nums[idx], nums[p]
                    p += 1
            nums[p], nums[r] = nums[r], nums[p] # put the pivot to the desired location
            
            if p > target: 
                return quickselect(nums, l, p-1)
            elif p < target: 
                return quickselect(nums, p+1, r)
            else:
                return nums[p]
        return quickselect(nums, 0, len(nums)-1)
        
        
        
        
        """
        minheap = []
        for num in nums:
            heapq.heappush(minheap, num)
            
        while len(minheap) > k:
            heapq.heappop(minheap)
        return minheap[0]
        """
        