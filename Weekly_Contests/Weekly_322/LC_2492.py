# Written by: Jian-Yuan Lin
# Date: 2022.12.03

# DFS based
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

# BFS based
class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:

        # find the min dist in the group of roads connected from 1 -> n
        graph = collections.defaultdict(list)
        for start, end, cost in roads:
            graph[start].append((end, cost))
            graph[end].append((start, cost))
        
        q = collections.deque()
        q.append((1))
        seen = set()
        seen.add(1)
        connect_road = set()
        ans = float('inf')
        while q:
            size = len(q)
            for _ in range(size):
                cur = q.popleft()
                if cur == n:
                    continue
                for nxt, cost in graph[cur]:
                    if nxt not in seen:
                        seen.add(nxt)
                        q.append(nxt)
        
        for start, end, cost in roads:
            if start in seen or end in seen:
                ans = min(ans, cost)
        return ans