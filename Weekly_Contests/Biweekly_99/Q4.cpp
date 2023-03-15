class Solution {
public:
    int correct_guess(int i, int prev, unordered_map<int, unordered_map<int, int>>& mem, unordered_map<int, unordered_map<int, int>>& seen, unordered_map<int, vector<int>>& graph){
        if (mem.count(i) && mem[i].count(prev)){
            return mem[i][prev];
        }
        mem[i][prev] = 0;
        for (int nxt: graph[i]){
            //cout << i << " " << nxt << endl;
            if (nxt == prev){
                continue;
            }
            if (seen.count(i) && seen[i].count(nxt)){
                //cout << i << " " << prev << endl;
                mem[i][prev]++;
            }
            mem[i][prev] += correct_guess(nxt, i, mem, seen, graph);
        }
        return mem[i][prev];
    }

    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1;
        unordered_map<int, vector<int>> graph;
        for (vector<int> e : edges){
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        unordered_map<int, unordered_map<int, int>> seen;
        for (vector<int> g : guesses){
            int u = g[0], v = g[1];
            seen[u][v] = 1;
        }
        unordered_map<int, unordered_map<int, int>> mem;

        int ans = 0;
        for (int i = 0; i < n; i++){
            int correct = correct_guess(i, -1, mem, seen, graph);
            //cout << i << " " << correct << endl;
            if (correct >= k){
                ans++;
            }
        }
        return ans;
    }
};