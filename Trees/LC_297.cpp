// Written by: Jian-Yuan Lin
// Date: 2022.11.30

class Codec {
public:
    // learn to use ostringstream and istringstream to represent the string
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        encode(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return decode(in);
    }

private:
    void encode(TreeNode* root, ostringstream& out){
        if (root == nullptr){
            out << "# ";
            return;
        }
        out << root->val << " ";
        encode(root->left, out);
        encode(root->right, out); 
    }
    TreeNode* decode(istringstream& in){
        string str;
        in >> str;
        if (str == "#"){
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(str));
        root->left = decode(in);
        root->right = decode(in);
        return root;
    }
};
