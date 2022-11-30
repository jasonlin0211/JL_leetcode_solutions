// Written by: Jian-Yuan Lin
// Date: 2022.11.29

class Solution {
public:
    int goodNodes(TreeNode* root) {
        search(root, INT_MIN);
        return ans;
    }
private:
    int ans = 0;
    void search(TreeNode* root, int prev_max){
        if (root == nullptr){
            return;
        }
        if (root->val >= prev_max){
            ans += 1;
        }
        search(root->left, max(prev_max, root->val));
        search(root->right, max(prev_max, root->val));
    }
};