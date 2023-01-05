# Written by: Jian-Yuan Lin
# Date: 2023.01.04

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key = lambda x: x[1]) # sort based on the end time
        right = points[0][1]
        ans = 1
        # gradually update the right bound if the right bound can't include the new interval
        for point in points:
            if point[0] > right:
                right = point[1]
                ans += 1
        return ans 