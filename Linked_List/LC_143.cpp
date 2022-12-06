// Written by: Jian-Yuan Lin
// Date: 2022.12.05

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
    void reorderList(ListNode* head) {
        // this problem is tricky! don't underestimate it
        if (head->next == NULL) {
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        // split the list to two halves
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = nullptr;
        ListNode* reversed = reverse(slow);
        //print_list(head);
        //print_list(reversed);
        merge(head, reversed);
    
    }
private:
    ListNode* reverse(ListNode* root){
        if (root == nullptr || root->next == nullptr){
            return root;
        }
        ListNode* nxt = reverse(root->next);
        root->next->next = root;
        root->next = nullptr;
        return nxt;
    }

    void merge(ListNode* p1, ListNode* p2){
        while(p1 != nullptr){
            ListNode* temp1 = p1->next;
            ListNode* temp2 = p2->next;
            p1->next = p2;
            if (temp1 == nullptr){
                break;
            }
            p2->next = temp1;
            p1 = temp1;
            p2 = temp2;
        }
    }


    void print_list(ListNode* root){
        ListNode* temp = root;
        while (temp != nullptr){
            cout << temp -> val << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};