
# Written by: Jian-Yuan Lin
# Date: 2022.11.17

"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return node
        mapping = collections.defaultdict(Node)

        def dfs(node):
            if node.val in mapping:
                return mapping[node.val]
            new_node = Node(node.val)
            mapping[node.val] = new_node
            for nxt in node.neighbors:
                mapping[node.val].neighbors.append(dfs(nxt))
            return mapping[node.val]
        dfs(node)
        return mapping[node.val]