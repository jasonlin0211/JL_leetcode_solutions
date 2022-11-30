# Written by: Jian-Yuan Lin
# Date: 2022.11.30

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.ans = -float('inf')

        def find_max(root):
            if not root:
                return 0
            # be careful here, as the subtree sum could be negative!
            l = max(0, find_max(root.left))
            r = max(0, find_max(root.right))
            self.ans = max(self.ans, root.val + l + r)
            return max(l, r) + root.val
        find_max(root)
        return self.ans