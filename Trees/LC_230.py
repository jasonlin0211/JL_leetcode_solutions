# Written by: Jian-Yuan Lin
# Date: 2022.11.30

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        # use stack to simulate inorder traversal
        cur = root
        stack = []
        while cur or stack:
            while cur:
                stack.append(cur)
                cur = cur.left
            #print(stack)
            cur = stack.pop()
            k -= 1
            if k == 0:
                return cur.val
            cur = cur.right