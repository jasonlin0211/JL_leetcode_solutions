// Written by: Jian-Yuan Lin
// Date: 2022.11.30

// This solution is from Neetcode.io, I haven't written my own version using only index to indicate the range
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return build(preorder, inorder, index, 0, inorder.size() - 1);
    }
private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& index, int i, int j) {
        if (i > j) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[index]);
        
        int split = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (preorder[index] == inorder[i]) {
                split = i;
                break;
            }
        }
        index++;
        
        root->left = build(preorder, inorder, index, i, split - 1);
        root->right = build(preorder, inorder, index, split + 1, j);
        
        return root;
    }
};

// reconstruct vector is not efficient, see the better solution 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder);
    }
private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder){
        if (preorder.size() == 0 || inorder.size() == 0){
            return nullptr;
        }
        int root_val = preorder[0];
        TreeNode* root = new TreeNode(root_val);
        int pos = 0;
        while (inorder[pos] != root_val){
            pos += 1;
        }
        vector<int> left_preorder, left_inorder;
        for (int i = 0; i < pos; i++){
            left_preorder.push_back(preorder[1 + i]);
            left_inorder.push_back(inorder[i]);
        }
        root->left = build(left_preorder, left_inorder);
        vector<int> right_preorder, right_inorder;
        for (int i = pos + 1; i < inorder.size(); i++){
            right_preorder.push_back(preorder[i]);
            right_inorder.push_back(inorder[i]);
        }
        root->right = build(right_preorder, right_inorder);
        return root;
    }
};