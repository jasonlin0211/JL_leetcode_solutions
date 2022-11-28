# Written by: Jian-Yuan Lin
# Date: 2022.11.22

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        curr = head
        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        return prev
        
        """
        # recursive
        def reverse(head):
            if not head or not head.next:
                return head
            nxt = reverse(head.next)
            head.next.next = head
            head.next = None
            return nxt
        return reverse(head)
        """