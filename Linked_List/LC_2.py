# Written by: Jian-Yuan Lin
# Date: 2022.12.05

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # this is a very important yet tricky problem!
        if not l1: return l2
        if not l2: return l1
        dummy = ListNode(0)
        cur = dummy
        carry = 0
        while l1 or l2 or carry:
            total = (l1.val if l1 else 0) + (l2.val if l2 else 0) + carry
            cur.next = ListNode(total % 10)
            cur = cur.next
            carry = total // 10
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        
        return dummy.next