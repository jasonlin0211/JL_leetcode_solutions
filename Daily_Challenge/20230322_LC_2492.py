class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        graph = collections.defaultdict(list)
        for start, end, cost in roads:
            graph[start].append((end, cost))
            graph[end].append((start, cost))
        ans = float('inf')
        seen = set()
        def dfs(x):
            nonlocal ans
            seen.add(x)
            for nxt, cost in graph[x]:
                ans = min(ans, cost)
                if nxt not in seen:
                    dfs(nxt)
        dfs(1)
        return ans