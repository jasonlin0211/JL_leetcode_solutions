// Written by: Jian-Yuan Lin
// Date: 2022.11.29

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return search(root, p->val, q->val);
    }
private:
    TreeNode* search(TreeNode* root, int pval, int qval){
        if (root == nullptr){
            return root;
        }
        if (root->val < pval && root->val < qval){
            return search(root->right, pval, qval);
        }
        else if(root->val > pval && root->val > qval){
            return search(root->left, pval, qval);
        }
        else{
            return root;
        }
    }
};