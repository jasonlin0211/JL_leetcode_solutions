// Written by: Jian-Yuan Lin
// Date: 2022.12.06

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
    int cal_subtree_sum(TreeNode* root, vector<long>& nums){
        if (root == nullptr){
            return 0;
        }
        long l = cal_subtree_sum(root->left, nums);
        long r = cal_subtree_sum(root->right, nums);
        long total = l + r + root->val;
        nums.push_back(total);
        return total;
    }

    int maxProduct(TreeNode* root) {
        int kMod = pow(10, 9) + 7;
        // be very careful about the number size
        // we need to use long to prevent any potential overflow!
        vector<long> sub_tree_sum_vec;
        long total = cal_subtree_sum(root, sub_tree_sum_vec);
        long ans = 0;
        for (long val: sub_tree_sum_vec){
            long temp = (total - val) * val;
            ans = max(ans, temp);
        }
        return (int)(ans % kMod);
    }
};