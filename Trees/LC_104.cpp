// Written by: Jian-Yuan Lin
// Date: 2022.11.29

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return cal_dep(root);
    }
private:
    int cal_dep(TreeNode* root){
        if (root == nullptr){
            return 0;
        }
        int l = cal_dep(root->left), r = cal_dep(root->right);
        return 1 + max(l, r);
    }
};