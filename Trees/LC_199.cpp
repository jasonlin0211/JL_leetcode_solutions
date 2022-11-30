// Written by: Jian-Yuan Lin
// Date: 2022.11.29

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr){
            return {};
        }
        // BFS method search by layer
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int n = q.size();
            for (int i = 0; i < n; i++){
                TreeNode* cur = q.front();
                q.pop();
                if (i == n-1){
                    ans.push_back(cur->val);
                }
                if (cur->left != nullptr){
                    q.push(cur->left);
                }
                if (cur->right != nullptr){
                    q.push(cur->right);
                }
            }
        }
        // DFS method
        //dfs(root, 0);
        return ans;
    }
private:
    vector<int> ans;
    void dfs(TreeNode* root, int d){
        if (root == nullptr){
            return;
        }
        if (d == ans.size()){
            ans.push_back(root->val);
        }
        if (root->right != nullptr){
            dfs(root->right, d+1);
        }
        if (root->left != nullptr){
            dfs(root->left, d+1);
        }

    }
};