// Written by: Jian-Yuan Lin
// Date: 2023.01.09

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // this problem is very tricky...
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = dummy->next;
        ListNode* temp = NULL;
        int count = k;

        while (curr != nullptr){
            // reverse k elements
            // d->1->2->3
            if (count > 1){
                temp = prev->next; // remember 1
                prev->next = curr->next; // d->2
                curr->next = curr->next->next; // 1->3
                prev->next->next = temp; // 2->1, up to here, d->2->1->3
                count--; // repeat k-1 times to finish the reverse
            }
            // connect 
            else{
                prev = curr; // mark the last node of this group as the dummy node for the next reversed group
                curr = curr->next;
                count = k; // reset the reverse count
                ListNode* end = curr;
                // check if there's enough nodes for the reverse process
                for (int i = 0; i < k; i++){
                    if (end == nullptr){
                        return dummy->next;
                    }
                    end = end->next;
                }
            }
        }
        return dummy->next;
    }
};