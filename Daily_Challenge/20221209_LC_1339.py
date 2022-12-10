# Written by: Jian-Yuan Lin
# Date: 2022.12.09

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        kMod = 10**9 + 7
        sub_tree_sum_list = []
        def cal_subtree_sum(root):
            if not root:
                return 0
            l = cal_subtree_sum(root.left)
            r = cal_subtree_sum(root.right)
            sub_tree_sum_list.append(l + r + root.val)
            return l + r + root.val
        total = cal_subtree_sum(root)
        #print(sub_tree_sum_list, total)

        ans = 0
        for val in sub_tree_sum_list:
            ans = max(ans, (total - val) * val)
        return ans % kMod
        

        
        