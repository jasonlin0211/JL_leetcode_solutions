class Solution:
    
    def countWays(self, A: List[List[int]]) -> int:
        # mind blown....
        pre = -1
        res = 0
        for a,b in sorted(A):
            res += pre < a
            pre = max(pre, b)
        return pow(2, res, 10**9+7)



    def countWays(self, ranges: List[List[int]]) -> int:
        # Union find + interval sort + overlapping, good question!
        ranges.sort(key=lambda x:x[0])
        #print(ranges)
        n = len(ranges)
        root = [i for i in range(n)]

        idx = 0
        
        def is_overlap(l1, l2):
            return l1[1] >= l2[0]
        
        def find(x):
            if x != root[x]:
                root[x] = find(root[x])
            return root[x]
        
        def union(x, y):
            rx, ry = find(x), find(y)
            if rx != ry:
                root[ry] = rx

        while idx < n:
            cur = ranges[idx]
            j = idx + 1
            while j < n and is_overlap(cur, ranges[j]):
                union(idx, j)
                cur = [min(cur[0], ranges[j][0]), max(cur[1], ranges[j][1])]
                j += 1
            idx = j
        count = collections.defaultdict(list)
        for i in range(n):
            count[root[i]].append(i)
        #print(count)
        return (2 ** (len(count))) % (10**9 + 7)