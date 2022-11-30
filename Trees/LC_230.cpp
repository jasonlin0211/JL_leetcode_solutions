// Written by: Jian-Yuan Lin
// Date: 2022.11.30

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // iterative inorder traversal using stack
        stack<TreeNode*> s;
        TreeNode* cur = root;

        while(!s.empty() || cur != nullptr){
            while (cur != nullptr){
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            cout << cur->val << endl;
            s.pop();
            k -= 1;
            if (k == 0){
                return cur->val;
            }
            cur = cur->right;
        }
        return -1;
        /*
        / brute force - inorder traverse then return the item in array
        vector<int> ans;
        inorder(root, ans);
        return ans[k-1];*/
    }
private:
    void inorder(TreeNode* root, vector<int>& ans){
        if (root == nullptr){
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
};