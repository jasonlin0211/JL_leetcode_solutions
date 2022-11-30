# Written by: Jian-Yuan Lin
# Date: 2022.11.29

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        def cal_height(root):
            if not root:
                return 0
            l = cal_height(root.left)
            r = cal_height(root.right)
            return 1 + max(l, r)
        
        return abs(cal_height(root.left) - cal_height(root.right)) <= 1 and self.isBalanced(root.left) and self.isBalanced(root.right)