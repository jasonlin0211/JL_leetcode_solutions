# Written by: Jian-Yuan Lin
# Date: 2022.11.27

class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        val = []
        cur = head
        while cur:
            val.append(cur.val)
            cur = cur.next
        n = len(val)
        nxt_greater = [-1] * n
        stack = []
        
        for i, v in enumerate(val):
            while stack and val[stack[-1]] < v:
                idx = stack.pop()
                nxt_greater[idx] = i
            stack.append(i)
        exist = []
        for i, v in enumerate(nxt_greater):
            if v == -1:
                exist.append(val[i])
        dummy = ListNode(0)
        cur = dummy
        for e in exist:
            cur.next = ListNode(e)
            cur = cur.next
        cur.next = None
        return dummy.next
        """
        # I still don't know why this doesn't work...
        exist = set()
        for i, v in enumerate(nxt_greater):
            if v == -1:
                exist.add((i, val[i]))
        
        dummy = ListNode(0)
        prev = dummy
        for i, v in enumerate(val):
            if (i, v) in exist:
                prev.next = ListNode(v)
                prev = prev.next
        prev.next = None
        return dummy.next
            
        """
        