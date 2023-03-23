/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy* dfs(Node* root, unordered_map<Node*, NodeCopy*>& mapping){
        if (root == nullptr){
            return nullptr;
        }
        if (mapping.count(root)){
            return mapping[root];
        }
        mapping[root] = new NodeCopy(root->val);
        mapping[root]->left = dfs(root->left, mapping);
        mapping[root]->right = dfs(root->right, mapping);
        mapping[root]->random = dfs(root->random, mapping);
        return mapping[root];
    }
    NodeCopy* copyRandomBinaryTree(Node* root) {
        unordered_map<Node*, NodeCopy*> mapping;
        return dfs(root, mapping);
    }
};