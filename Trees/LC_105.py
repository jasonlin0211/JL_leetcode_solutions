# Written by: Jian-Yuan Lin
# Date: 2022.11.30

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        # first node in preorder is always going to be root
        # find the location of root in the inorder, then the previous part
        # is left subtree, and the following part is the right subtree!
        
        def build(preorder, inorder):
            if not preorder or not inorder:
                return None
            root_val = preorder[0]
            root = TreeNode(root_val)
            idx = 0
            # find the location of root in the inorder array
            while inorder[idx] != root_val:
                idx += 1
            # build left subtree
            root.left = build(preorder[1:1+idx], inorder[:idx])
            # build right subtree
            root.right = build(preorder[1+idx:], inorder[idx+1:])
            
            return root
        return build(preorder, inorder)