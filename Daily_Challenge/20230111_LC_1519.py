# Written by: Jian-Yuan Lin
# Date: 2023.01.11

class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
            
        # for every node, record the count of 26 chars, and then add the node it self, similar to post order traversal
        count = collections.defaultdict(list)
        def dfs(prev, node):
            ans = [0] * 26
            for nxt in graph[node]:
                if nxt == prev:
                    continue
                temp = dfs(node, nxt)
                for i in range(26):
                    ans[i] += temp[i]
            ans[ord(labels[node]) - ord('a')] += 1
            count[node] = ans
            return ans
        total = dfs(-1, 0)
        res = [0] * n
        for i in range(n):
            res[i] = count[i][ord(labels[i]) - ord('a')]
        return res