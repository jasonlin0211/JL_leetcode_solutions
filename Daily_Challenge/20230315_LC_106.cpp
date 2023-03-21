/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int l, int r, unordered_map<int, int>& inorder_pos){
        if (l > r){
            return nullptr;
        }
        int val = postorder.back();
        postorder.pop_back();
        TreeNode* root = new TreeNode(val);
        int idx = inorder_pos[val];
        
        root->right = build(inorder, postorder, idx+1, r, inorder_pos);
        root->left = build(inorder, postorder, l, idx-1, inorder_pos);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorder_pos;
        for (int i = 0; i < inorder.size(); i++){
            inorder_pos[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, inorder.size() - 1, inorder_pos);
    }
};