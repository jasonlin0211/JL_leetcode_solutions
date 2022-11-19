// Written by: Jian-Yuan Lin
// Date: 2022.11.18

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> root(n, 0);
        for (int i = 0; i < n; i++){
            root[i] = i;
        }
        vector<int> ans;
        for(vector<int> edge: edges){
            int first = edge[0], second = edge[1];
            if (!uni(first-1, second-1, root)){
                ans = {first, second};
                break;
            }
        }
        return ans;
    }
private:
    int find(int x, vector<int>& root){
        if (x != root[x]){
            root[x] = find(root[x], root);
        }
        return root[x];
    }

    bool uni(int x, int y, vector<int>& root){
        int rx = find(x, root), ry = find(y, root);
        if (rx != ry){
            root[ry] = rx;
            return true;
        }
        
        return false;
    }

};