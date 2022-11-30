# Written by: Jian-Yuan Lin
# Date: 2022.11.30

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        minheap = []
        intervals.sort()
        for start, end in intervals:
            if not minheap:
                heapq.heappush(minheap, end)
            else:
                if minheap[0] <= start:
                    heapq.heappop(minheap)
                heapq.heappush(minheap, end)
        
        return len(minheap)