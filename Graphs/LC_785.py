# Written by: Jian-Yuan Lin
# Date: 2022.12.04

class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        # check if the graph is biparitate
        color = [0] * n
        def dfs(i, c):
            color[i] = c
            for nxt in graph[i]:
                if color[nxt] == c or (color[nxt] == 0 and not dfs(nxt, -c)):
                    return False
            return True
        for i in range(n):
            if color[i] == 0:
                if not dfs(i, 1):
                    return False
        return True