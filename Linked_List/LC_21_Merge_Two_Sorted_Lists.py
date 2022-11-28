# Written by: Jian-Yuan Lin
# Date: 2022.11.22

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        def merge(l1, l2):
            if not l2:
                return l1
            if not l1:
                return l2
            if l1.val < l2.val:
                l1.next = merge(l1.next, l2)
                return l1
            else:
                l2.next = merge(l1, l2.next)
                return l2
        return merge(list1, list2)

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        cur = dummy
        ptr1, ptr2 = list1, list2
        
        while ptr1 and ptr2:
            if ptr1.val < ptr2.val:
                cur.next = ListNode(ptr1.val)
                cur = cur.next
                ptr1 = ptr1.next
            else:
                cur.next = ListNode(ptr2.val)
                cur = cur.next
                ptr2 = ptr2.next
        
        if ptr1:
            while ptr1:
                cur.next = ListNode(ptr1.val)
                cur = cur.next
                ptr1 = ptr1.next
        if ptr2:
            while ptr2:
                cur.next = ListNode(ptr2.val)
                cur = cur.next
                ptr2 = ptr2.next
                
        return dummy.next