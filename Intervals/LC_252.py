# Written by: Jian-Yuan Lin
# Date: 2022.11.30

class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        intervals.sort(key = lambda x:x[0])
        def is_overlap(p1, p2):
            return p1[1] > p2[0]
        
        for i in range(len(intervals) - 1):
            if is_overlap(intervals[i], intervals[i+1]):
                return False
        return True