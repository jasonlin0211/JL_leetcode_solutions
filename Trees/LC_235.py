# Written by: Jian-Yuan Lin
# Date: 2022.11.29

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def check(root, p, q):
            if not root:
                return None
            if root.val < p.val and root.val < q.val:
                return check(root.right, p, q)
            elif root.val > p.val and root.val > q.val:
                return check(root.left, p, q)
            else:
                return root
        return check(root, p, q)