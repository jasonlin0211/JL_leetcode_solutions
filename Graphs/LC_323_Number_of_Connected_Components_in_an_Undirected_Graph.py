# Written by: Jian-Yuan Lin
# Date: 2022.11.18

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        root = [i for i in range(n)]
        total = n

        def find(x):
            if root[x] != x:
                root[x] = find(root[x])
            return root[x]
        
        def union(x, y):
            rx, ry = find(x), find(y)
            nonlocal total
            if rx != ry:
                root[ry] = rx
                total -= 1

        for v1, v2 in edges:
            union(v1, v2)
        return total