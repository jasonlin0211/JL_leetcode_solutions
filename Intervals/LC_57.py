# Written by: Jian-Yuan Lin
# Date: 2022.11.30

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        ans = []
        
        for i in range(len(intervals)):
            # not overlapped, new interval can be inserted before the following intervals
            if newInterval[1] < intervals[i][0]:
                ans.append(newInterval)
                return ans + intervals[i:]
            # not overlapped, new interval can be inserted after the current interval
            elif newInterval[0] > intervals[i][1]:
                ans.append(intervals[i])
            # overlapped, change the to be inserted new interval
            else:
                newInterval = [min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])]
        
        ans.append(newInterval)
        return ans