// Written by: Jian-Yuan Lin
// Date: 2022.11.29

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr){
            return true;
        }
        if (root == nullptr || subRoot == nullptr){
            return false;
        }
        return check(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
private:
    bool check(TreeNode* p, TreeNode* q){
        if (p == nullptr && q == nullptr){
            return true;
        }
        if (p == nullptr || q == nullptr){
            return false;
        }
        return p->val == q->val && check(p->left, q->left) && check(p->right, q->right);
    }
};