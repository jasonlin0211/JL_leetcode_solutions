class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        # union find based method
        root = [i for i in range(n)]
        counts = [1] * n
        # path compression
        def find(x):
            if x != root[x]:
                root[x] = find(root[x])
            return root[x]
        # union
        def union(x, y):
            rx, ry = find(x), find(y)
            if rx != ry:
                root[ry] = rx
                counts[rx] += counts[ry]
        
        for v1, v2 in edges:
            union(v1, v2)
        ans = 0
        for i in range(n):
            ans += n - counts[find(i)]
        return ans // 2
        
        
        """
        # DFS based method
        # find the connected component
        # the answer is (sum(n - cc_size)) / 2
        graph = collections.defaultdict(list)
        for v1, v2 in edges:
            graph[v1].append(v2)
            graph[v2].append(v1)
        seen = [0] * n
        ans = 0
        # find the CCs size
        def dfs(node, seen):
            if seen[node]:
                return 0
            seen[node] = 1
            ans = 1
            for nxt in graph[node]:
                ans += dfs(nxt, seen)
            return ans
            
        
        for i in range(n):
            # this node is part of the previous calculated CCs
            if seen[i]:
                continue
            cur = dfs(i, seen) # find the CCs size
            ans += (n - cur) * cur
        return ans // 2
        
        """