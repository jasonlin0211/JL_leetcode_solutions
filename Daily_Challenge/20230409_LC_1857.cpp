class Solution {
public:
    int dfs(int cur, unordered_map<int, vector<int>>& graph,string& colors, unordered_set<int>& path, unordered_set<int>& visit, vector<vector<int>>& count){
        // cycle
        if (path.count(cur)){
            return INT_MAX;
        }
        if (visit.count(cur)){
            return 0;
        }
        visit.insert(cur);
        path.insert(cur);
        int coloridx = colors[cur] - 'a'; 
        count[cur][coloridx]++; // mark the current color for the current node
        for (int nxt: graph[cur]){
            // detect cycle later, just return cycle
            if (dfs(nxt, graph, colors, path, visit, count) == INT_MAX){
                return INT_MAX;
            }
            for (int i = 0; i < 26; i++){
                if (i == coloridx){
                    count[cur][i] = max(count[cur][i], count[nxt][i] + 1);
                }
                else{
                    count[cur][i] = max(count[cur][i], count[nxt][i]);
                }
            }
        }
        path.erase(cur); 
        return *max_element(count[cur].begin(), count[cur].end());
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // build graph
        unordered_map<int, vector<int>> graph;
        for (vector<int>& e: edges){
            int u = e[0], v = e[1];
            graph[u].push_back(v);
        }

        int n = colors.size();
        unordered_set<int> visit, path;
        vector<vector<int>> count(n, vector<int>(26, 0)); // count for the given nodes, the color counts
        int ans = 0;
        for (int i = 0; i < n; i++){
            ans = max(ans, dfs(i, graph, colors, path, visit, count));
        }
        if (ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};