# Written by: Jian-Yuan Lin
# Date: 2022.11.18

class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        # union find based method
        root = [i for i in range(n)]
        self.total = n
        def find(x):
            if root[x] != x:
                root[x] = find(root[x])
            return root[x]
        
        def union(x, y):
            rx, ry = find(x), find(y)
            if rx != ry:
                root[ry] = rx
                self.total -= 1
                return True
            else:
                return False
        
        for v1, v2 in edges:
            if not union(v1, v2):
                return False
        return self.total == 1
        

        """
        mapping = collections.defaultdict(list)
        for v1, v2 in edges:
            mapping[v1].append(v2)
            mapping[v2].append(v1)
        seen = set()

        def dfs(start, prev):
            if start in seen:
                return False
            seen.add(start)
            for nxt in mapping[start]:
                if nxt == prev:
                    continue
                if not dfs(nxt, start):
                    return False
            return True
        
        
        return dfs(0, -1) and len(seen) == n
        """
