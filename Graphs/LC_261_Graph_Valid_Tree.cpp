// Written by: Jian-Yuan Lin
// Date: 2022.11.18

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1){
            return false;
        } 
        vector<int> root;
        for (int i = 0; i < n; i++){
            root.push_back(i);
        }
        for (vector<int> edge: edges){
            if (!doUnion(edge[0], edge[1], root)){
                return false;
            }
        }
        return true;
    }
private:
    int find(int x, vector<int>& root){
        if (x != root[x]){
            root[x] = find(root[x], root);
        }
        return root[x];
    }

    bool doUnion(int x, int y, vector<int>& root){
        int rx = find(x, root), ry = find(y, root);
        if (rx != ry){
            root[ry] = rx;
            return true;
        }
        return false;
    }
};