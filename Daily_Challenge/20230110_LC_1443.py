# Written by: Jian-Yuan Lin
# Date: 2023.01.10

class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        # build graph
        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        def dfs(prev, node, item):
            total_time, child_time = 0, 0
            for nxt in graph[node]:
                if nxt == prev:
                    continue
                child_time = dfs(node, nxt, item)
                if child_time or item[nxt]:
                    total_time += child_time + 2 # after collect the child node's apple, we need to +2 since it takes one step to reach child and another step to come back
            return total_time

        return dfs(-1, 0, hasApple)