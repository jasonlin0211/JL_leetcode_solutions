class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        graph = collections.defaultdict(list)
        seen = set()
        for u, v in connections:
            seen.add((u,v))
            graph[u].append(v)
            graph[v].append(u)
        
        q = collections.deque()
        q.append(0)
        visited = set()
        visited.add(0)

        ans = 0

        while q:
            size = len(q)
            for _ in range(size):
                cur = q.popleft()
                for nxt in graph[cur]:
                    if nxt in visited:
                        continue
                    if (cur, nxt) in seen: # reverse the edge
                        ans += 1
                    q.append(nxt)
                    visited.add(nxt)
        return ans        