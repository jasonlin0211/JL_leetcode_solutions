// Written by: Jian-Yuan Lin
// Date: 2022.11.29

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr){
            return true;
        }
        int l = cal_height(root->left), r = cal_height(root->right);
        return (abs(l-r) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int cal_height(TreeNode* root){
        if (root == nullptr){
            return 0;
        }
        int l = cal_height(root->left), r = cal_height(root->right);
        return 1 + max(l, r);

    }
};