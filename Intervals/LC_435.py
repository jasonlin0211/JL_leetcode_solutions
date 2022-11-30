# Written by: Jian-Yuan Lin
# Date: 2022.11.30

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        ans = 0
        result = [intervals[0]]
        prev_end = intervals[0][1]
        for i in range(1, len(intervals)):
            start, end = intervals[i][0], intervals[i][1]
            if start >= prev_end:
                result.append(intervals[i])
                prev_end = result[-1][1]
            else:
                ans += 1
                prev_end = min(prev_end, end)
        return ans