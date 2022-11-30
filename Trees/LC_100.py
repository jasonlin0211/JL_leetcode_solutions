# Written by: Jian-Yuan Lin
# Date: 2022.11.29

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        def check(p, q):
            if not p and not q:
                return True
            if not p or not q:
                return False
            return p.val == q.val and check(p.left, q.left) and check(p.right, q.right)
        
        return check(p, q)