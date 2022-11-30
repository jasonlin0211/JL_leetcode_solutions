// Written by: Jian-Yuan Lin
// Date: 2022.11.29

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        return invert(root);   
    }
private:
    TreeNode* invert(TreeNode* root){
        if (root == nullptr){
            return root;
        }
        if (root->left == nullptr && root->right == nullptr){
            return root;
        }
        swap(root->left, root->right);
        invert(root->left);
        invert(root->right);
        return root;
    }
};