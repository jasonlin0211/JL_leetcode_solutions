# Written by: Jian-Yuan Lin
# Date: 2022.11.29

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        ans = []
        
        def preorder(root, prevmax):
            if not root:
                return
            if root.val >= prevmax:
                ans.append(root.val)
            preorder(root.left, max(prevmax, root.val))
            preorder(root.right, max(prevmax, root.val))
        
        preorder(root, -float('inf'))
        return len(ans)