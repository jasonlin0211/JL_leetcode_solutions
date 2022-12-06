# Written by: Jian-Yuan Lin
# Date: 2022.12.05

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head.next:
            return
        prev, slow, fast = None, head, head
        while fast and fast.next:
            fast = fast.next.next
            prev = slow
            slow = slow.next
        prev.next = None
        
        def reverse(head):
            if not head or not head.next:
                return head
            nxt = reverse(head.next)
            head.next.next = head
            head.next = None
            return nxt
        
        def merge(p1, p2):
            while p1:
                l1, l2 = p1.next, p2.next
                p1.next = p2
                if not l1:
                    break
                p2.next = l1
                p1, p2 = l1, l2
        
        merge(head, reverse(slow))