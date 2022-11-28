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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr){
            return head;
        }
        // Iteratively
        // note C++ doesn't allow multiple point assignment in one line, i.e ListNode* prev = nullptr, cur = head; is not allowed
        ListNode* prev = nullptr;
        ListNode* cur = head;
        
        while (cur != nullptr){
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};

// Recursively
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(head);
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
};