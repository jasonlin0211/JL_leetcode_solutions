// Written by: Jian-Yuan Lin
// Date: 2022.11.22

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return merge(list1, list2);
    }
private: 
    ListNode* merge(ListNode* l1, ListNode* l2){
        if (l1 == nullptr){
            return l2;
        }
        if (l2 == nullptr){
            return l1;
        }
        if (l1->val < l2->val){
            l1->next = merge(l1->next, l2);
            return l1;
        }
        else{
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        ListNode* p = list1;
        ListNode* q = list2;

        while (p != nullptr && q != nullptr){
            if (p->val < q->val){
                cur->next = new ListNode(p->val);
                p = p->next;
            }
            else{
                cur->next = new ListNode(q->val);
                q = q->next;
            }
            cur = cur->next;
        }
        while (p != nullptr){
            cur->next = new ListNode(p->val);
            p = p->next; 
            cur = cur->next;
        }
        while (q != nullptr){
            cur->next = new ListNode(q->val);
            q = q->next; 
            cur = cur->next;
        }
        return dummy->next;
    }
};