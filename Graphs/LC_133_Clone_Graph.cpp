// Written by: Jian-Yuan Lin
// Date: 2022.11.17

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // Neetcode's solution is more clean and concise
        // https://github.com/neetcode-gh/leetcode/blob/main/cpp/neetcode_150/11_graphs/clone_graph.cpp
        if (node == nullptr){
            return node;
        }
        unordered_map<int, Node*> mapping;
        
        return dfs(mapping, node);
    }
private:
    Node* dfs(unordered_map<int, Node*>& mapping, Node* node){
        if (node == nullptr){
            return node;
        }
        if (mapping.count(node->val)){
            return mapping[node->val];
        }
        Node* new_node = new Node(node->val);
        mapping[node->val] = new_node;
        for (Node* n: node->neighbors){
            mapping[node->val]->neighbors.push_back(dfs(mapping, n));
        }
        return mapping[node->val];
    }
};