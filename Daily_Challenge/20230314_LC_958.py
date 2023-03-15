class Solution:
    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
        q = collections.deque()
        q.append(root)

        while q:
            cur = q.popleft()
            if cur:
                q.append(cur.left)
                q.append(cur.right)
            else:
                while q:
                    if q.popleft():
                        return False
        return True