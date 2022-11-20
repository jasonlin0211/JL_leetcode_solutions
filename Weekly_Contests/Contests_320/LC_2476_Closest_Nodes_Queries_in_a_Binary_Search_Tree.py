# Written by: Jian-Yuan Lin
# Date: 2022.11.19

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def closestNodes(self, root: Optional[TreeNode], queries: List[int]) -> List[List[int]]:
        n = len(queries)
        nums = []
        def inorder(root):
            if not root:
                return
            inorder(root.left)
            nums.append(root.val)
            inorder(root.right)
        inorder(root)
        
        def find_lower(nums, val):
            l, r = 0, len(nums)
            while l < r:
                mid = l + (r-l)//2
                if nums[mid] > val:
                    r = mid
                else:
                    l = mid + 1
            
            if l == 0 and nums[l] > val:
                return -1
            return nums[l-1]
        
        def find_upper(nums, val):
            l, r = 0, len(nums)
            while l < r:
                mid = l + (r-l)//2
                if nums[mid] >= val:
                    r = mid
                else:
                    l = mid + 1
            if l == len(nums):
                return -1
            return nums[l]
        
        ans = []
        for q in queries:
            ans.append([find_lower(nums, q), find_upper(nums, q)])
        
        return ans