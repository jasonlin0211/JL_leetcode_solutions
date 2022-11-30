# Written by: Jian-Yuan Lin
# Date: 2022.11.30

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key = lambda x:x[0])
        
        ans = []
        ans.append(intervals[0])
        
        def is_overlap(l1, l2):
            return l1[1] >= l2[0]
        
        def merge_intervals(l1, l2):
            return [min(l1[0], l2[0]), max(l1[1], l2[1])]
        
        for i in range(1, len(intervals)):
            to_insert = intervals[i]
            if is_overlap(ans[-1], to_insert):
                to_merge = ans.pop()
                new_interval = merge_intervals(to_merge, to_insert)
                ans.append(new_interval)
            else:
                ans.append(to_insert)
        return ans