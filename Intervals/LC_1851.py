# Written by: Jian-Yuan Lin
# Date: 2022.11.30

class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        intervals.sort()
        result = {}
        i = 0
        minheap = []
        for q in sorted(queries):
            while i < len(intervals) and intervals[i][0] <= q:
                r, l = intervals[i][1], intervals[i][0] 
                heapq.heappush(minheap, (r-l+1, r))
                i += 1
            # pop the impossible pairs
            while minheap and minheap[0][1] < q:
                heapq.heappop(minheap)
            result[q] = minheap[0][0] if minheap else -1
        ans = []
        for q in queries:
            ans.append(result[q])
        return ans