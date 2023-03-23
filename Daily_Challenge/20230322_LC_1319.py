class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        root = [i for i in range(n)]

        def find(x):
            if x != root[x]:
                root[x] = find(root[x])
            return root[x]
        
        def union(x, y):
            rx, ry = find(x), find(y)
            if rx != ry:
                root[ry] = rx
                return 0
            return 1
        avail_cable = 0
        
        for u, v in connections:
            avail_cable += union(u, v)
        seen = set()
        for i in range(len(root)):
            seen.add(find(root[i]))
        if avail_cable >= len(seen) - 1:
            return len(seen) - 1
        return -1