class Solution {
public:
    int find(int x, vector<int>& root){
        if (root[x] != x){
            root[x] = find(root[x], root);
        }
        return root[x];
    }

    void do_union(int x, int y, vector<int>& root, vector<int>& count){
        int rx = find(x, root), ry = find(y, root);
        if (rx != ry){
            root[ry] = rx;
            count[rx] += count[ry];
        }
    }
    void print_vector(vector<int>& arr){
        for (int i = 0; i < arr.size(); i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> root(n, 0), count(n, 1);
        for (int i = 0; i < n; i++){
            root[i] = i;
        }
        for (vector<int> e: edges){
            do_union(e[0], e[1], root, count);
        }
        //print_vector(root);
        //print_vector(count);
        long long ans = 0;
       
        for (int i = 0; i < n; i++){
            int idx = find(i, root);
            ans += n - count[idx];
        }
        return ans/2;
    }
};