# Written by: Jian-Yuan Lin
# Date: 2022.11.29

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def invert(root):
            if not root:
                return root
            root.left, root.right = invert(root.right), invert(root.left)
            return root
        return invert(root)