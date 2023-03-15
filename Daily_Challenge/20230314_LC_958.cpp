class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if (cur != nullptr){
                q.push(cur->left);
                q.push(cur->right);
            }
            else{
                while (!q.empty()){
                    TreeNode* p = q.front();
                    q.pop();
                    if (p != nullptr){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};