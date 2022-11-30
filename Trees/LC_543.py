# Written by: Jian-Yuan Lin
# Date: 2022.11.29

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        ans = 0

        def find_max(root):
            if not root:
                return -1
            nonlocal ans
            l = find_max(root.left)
            r = find_max(root.right)
            ans = max(ans, 2 + l + r)
            return 1 + max(l, r)
        find_max(root)
        return ans