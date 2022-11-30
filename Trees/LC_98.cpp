// Written by: Jian-Yuan Lin
// Date: 2022.11.29

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // in CPP, the minval and maxval we need to use long
        // since it's possible that the root value is INT_MAX
        return check(root, LLONG_MIN, LLONG_MAX);
    }
private:
    bool check(TreeNode* root, long minval, long maxval){
        if (root == nullptr){
            return true;
        }
        if (root->val <= minval || root->val >= maxval){
            return false;
        }
        return check(root->left, minval, root->val) && check(root->right, root->val, maxval);
    }
};