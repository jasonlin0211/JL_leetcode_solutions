# Written by: Jian-Yuan Lin
# Date: 2022.11.29

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def check(root, minval, maxval):
            if not root:
                return True
            if root.val <= minval or root.val >= maxval:
                return False
            return check(root.left, minval, root.val) and check(root.right, root.val, maxval)
        return check(root, -float('inf'), float('inf'))