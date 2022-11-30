// Written by: Jian-Yuan Lin
// Date: 2022.11.29

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr){
            return {};
        }
        // BFS
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int size = q.size();
            ans.push_back({});
            for (int i = 0; i < size; i++){
                TreeNode* cur = q.front();
                q.pop();
                ans.back().push_back(cur->val);
                if (cur->left != nullptr){
                    q.push(cur->left);
                }
                if (cur->right != nullptr){
                    q.push(cur->right);
                }
            }
        }
        return ans;
        /* DFS based solution
        vector<vector<int>> ans;
        dfs(root, ans, 0);
        return ans;*/
    }
private:
    void dfs(TreeNode* root, vector<vector<int>>& ans, int d){
        if (root == nullptr){
            return;
        }
        if (d == ans.size()){
            ans.push_back({});
        }
        ans[d].push_back(root->val);
        dfs(root->left, ans, d+1);
        dfs(root->right, ans, d+1);
    }
};