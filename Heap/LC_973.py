# Written by: Jian-Yuan Lin
# Date: 2022.12.05

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        maxheap = []
        for point in points:
            dist = -(point[0]**2 + point[1]**2)
            heapq.heappush(maxheap,(dist, point))
            if len(maxheap) > k:
                heapq.heappop(maxheap)
        ans = []
        for item in maxheap:
            ans.append(item[1])
        return ans