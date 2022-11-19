# Written by: Jian-Yuan Lin
# Date: 2022.11.18

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        root = [i for i in range(n)]

        def find(x):
            if root[x] != x:
                root[x] = find(root[x])
            return root[x]
        
        def union(x, y):
            rx, ry = find(x), find(y)
            if rx != ry:
                root[ry] = rx
                return True
            return False
        
        for start, end in edges:
            if not union(start-1, end-1):
                return [start, end]
        