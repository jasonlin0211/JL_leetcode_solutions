class Solution {
public:

    int countWays(vector<vector<int>>& ranges) {
        // mind blown.....
        int res = 1, last = -1, mod = 1e9 + 7;
        sort(ranges.begin(), ranges.end());
        for (auto r: ranges) {   
            if (last < r[0])
                res = res * 2 % mod;
            last = max(last, r[1]);
        }
        return res;
    }

    int find(int x, vector<int>& root){
        if (x != root[x]){
            root[x] = find(root[x], root);
        }
        return root[x];
    }

    void do_union(int x, int y, vector<int>& root){
        int rx = find(x, root);
        int ry = find(y, root);
        if (rx != ry){
            root[ry] = rx;
        }
    }

    bool is_overlap(vector<int>& l1, vector<int>& l2){
        return l1[1] >= l2[0];
    }

    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        int n = ranges.size();
        
        vector<int> root;
        for (int i = 0; i < n; i++){
            root.push_back(i);
        }
        
        int idx = 0;

        while (idx < n){
            vector<int> cur = ranges[idx];
            int j = idx + 1;
            while (j < n && is_overlap(cur, ranges[j])){
                do_union(idx, j, root);
                cur = {min(cur[0], ranges[j][0]), max(cur[1], ranges[j][1])};
                j++;
            }
            idx = j;
        }
        unordered_map<int, vector<int>> count;
        for (int i = 0; i < n; i++){
            count[root[i]].push_back(i);
        }
        // to prevent int overflow....
        int ans = 1;
        for (int i = 0; i < count.size(); i++){
            ans = (ans * 2) % int(pow(10, 9) + 7); 
        }
        return ans;

    }
};