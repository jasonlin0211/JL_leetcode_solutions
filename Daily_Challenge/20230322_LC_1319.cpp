class Solution {
public:
    int find(int x, vector<int>& root){
        if (x != root[x]){
            root[x] = find(root[x], root);
        }
        return root[x];
    }

    int do_union(int x, int y, vector<int>& root){
        int rx = find(x, root), ry = find(y, root);
        if (rx == ry){
            return 1;
        }
        else{
            root[ry] = rx;
            return 0;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> root(n, 0);
        for (int i = 0; i < n; i++){
            root[i] = i;
        }
        int avail_cable = 0;
        for (vector<int> connect: connections){
            int u = connect[0], v = connect[1];
            avail_cable += do_union(u, v, root);
            //cout << u << " " << v << " " << avail_cable << endl;
        }
        // cout << avail_cable << endl;
        unordered_set<int> seen;
        for (int i = 0; i < n; i++){
            int x = find(root[i], root);
            seen.insert(x);
        }
        

        if (avail_cable >= seen.size() - 1){
            return seen.size() - 1;
        }
        return -1;
    }
};