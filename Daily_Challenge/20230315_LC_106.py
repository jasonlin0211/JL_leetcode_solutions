# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        inorder_pos = {}
        for i in range(len(inorder)):
            inorder_pos[inorder[i]] = i
        
        def build(l, r):
            if l > r:
                return None
            
            val = postorder.pop()
            root = TreeNode(val)
            idx = inorder_pos[val]
            root.right = build(idx+1, r)
            root.left = build(l, idx-1)
            return root
        
        return build(0, len(inorder) - 1)