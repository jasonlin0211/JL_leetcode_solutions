class Solution {
public:
    Node* dfs(Node* root, unordered_map<int, unordered_map<int, Node*>>& mapping, int height){
        if (root == nullptr){
            return nullptr;
        }
        mapping[height][root->val] = new Node(root->val);
        for (Node* nxt: root->children){
            mapping[height][root->val]->children.push_back(dfs(nxt, mapping, height+1));
        }
        return mapping[height][root->val];
    }

    Node* cloneTree(Node* root) {
        unordered_map<int, unordered_map<int, Node*>> mapping;
        return dfs(root, mapping, 0);
    }
};