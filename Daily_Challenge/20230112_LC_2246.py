# Written by: Jian-Yuan Lin
# Date: 2023.01.12

class Solution:
    def longestPath(self, parent: List[int], s: str) -> int:
        self.ans = 0
        graph = collections.defaultdict(list)
        for i in range(len(parent)):
            if i == 0:
                continue
            graph[parent[i]].append(i)
        # this is very tricky, for every node, we need to find the top 2 max length nodes, and then add these two length + 1 for left -> root -> right case
        # the function will return the max length include the root
        def dfs(root):
            nxt_length = [0] # need to put zero since we might have no values for the next level
            for nxt in graph[root]:
                val = dfs(nxt)
                if s[root] != s[nxt]:
                    nxt_length.append(val)
            top_two = nlargest(2, nxt_length)
            self.ans = max(self.ans, sum(top_two) + 1)
            return max(top_two) + 1
        
        dfs(0)
        return self.ans 