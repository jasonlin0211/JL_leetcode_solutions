# Written by: Jian-Yuan Lin
# Date: 2022.11.29

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        def find_depth(root):
            if not root:
                return 0
            l , r = find_depth(root.left), find_depth(root.right)
            return 1 + max(l, r)
        return find_depth(root)