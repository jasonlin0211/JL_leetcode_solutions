# Written by: Jian-Yuan Lin
# Date: 2022.11.29

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        # BFS
        if not root:
            return []
        ans = []
        q = collections.deque()
        q.append(root)
        
        while q:
            size = len(q)
            ans.append([])
            for _ in range(size):
                cur = q.popleft()
                ans[-1].append(cur.val)
                if cur.left:
                    q.append(cur.left)
                if cur.right:
                    q.append(cur.right)
        return ans
        
        
        
        """
        Recursive 
        ans = []
        def traverse(root, d):
            if not root:
                return
            if len(ans) == d:
                ans.append([])
            ans[d].append(root.val)
            traverse(root.left, d+1)
            traverse(root.right, d+1)
        
        traverse(root, 0)
        return ans
        """