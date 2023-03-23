class Solution {
public:
    void dfs(int x, unordered_map<int, vector<vector<int>>>& graph, vector<int>& seen){
        // if (x == n){
        //     return; 
        // }
        seen[x] = 1;
        for (vector<int> nxt: graph[x]){
            int nxt_node = nxt[0], nxt_cost = nxt[1];
            ans = min(ans, nxt_cost);
            if(seen[nxt_node] != 1){
                dfs(nxt_node, graph, seen);
            }
        }
        return;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        // find the minimum weight in this graph
        unordered_map<int, vector<vector<int>>> graph;
        for (vector<int> r: roads){
            int start = r[0] - 1, end = r[1] - 1, cost = r[2];
            graph[start].push_back({end, cost});
            graph[end].push_back({start, cost});
        }
        vector<int> seen(n, 0);
        ans = INT_MAX;
        dfs(0, graph, seen);
        return ans;
    }
private:
    int ans;
};