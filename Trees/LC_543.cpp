// Written by: Jian-Yuan Lin
// Date: 2022.11.29

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        find_max(root);
        return ans;
    }
private:
    int ans = 0;
    int find_max(TreeNode* root){
        if (root == nullptr){
            return -1;
        }
        int l = find_max(root->left), r = find_max(root->right);
        ans = max(ans, l + r + 2);
        return 1 + max(l, r);
    }
};