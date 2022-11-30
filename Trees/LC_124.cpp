// Written by: Jian-Yuan Lin
// Date: 2022.11.30

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        find_max(root);
        return ans;
    }
private:
    int ans = INT_MIN;
    int find_max(TreeNode* root){
        if (root == nullptr){
            return 0;
        }
        int l = max(0, find_max(root->left));
        int r = max(0, find_max(root->right));
        ans = max(ans, l + r + root->val);
        return root->val + max(l, r);
    }
};