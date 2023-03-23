# Definition for Node.
# class Node:
#     def __init__(self, val=0, left=None, right=None, random=None):
#         self.val = val
#         self.left = left
#         self.right = right
#         self.random = random

class Solution:
    def copyRandomBinaryTree(self, root: 'Optional[Node]') -> 'Optional[NodeCopy]':
        mapping = collections.defaultdict(NodeCopy)

        def dfs(root, mapping):
            if not root:
                return root
            
            if root in mapping:
                return mapping[root]
            
            result = NodeCopy(root.val)
            mapping[root] = result
            mapping[root].left = dfs(root.left, mapping)
            mapping[root].right = dfs(root.right, mapping)
            mapping[root].random = dfs(root.random, mapping)
            return mapping[root]
        
        return dfs(root, mapping)