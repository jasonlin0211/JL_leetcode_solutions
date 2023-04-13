class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // try topology sorting
        // build graph and indegrees
        int n = colors.size();
        vector<int> indegrees(n, 0);
        unordered_map<int, vector<int>> graph;
        for (vector<int>& e: edges){
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            indegrees[v]++;
        }
        queue<int> q;
        vector<vector<int>> count(n, vector<int>(26, 0)); // count for the given nodes, the color counts
        for(int i = 0; i < n; i++){
            if (indegrees[i] == 0){
                q.push(i);
            }
        }
        int total_edges = edges.size(), removed_edges = 0;
        int ans = 0;
        while (!q.empty()){
            int size = q.size();
            for (int iter = 0; iter < size; iter++){
                int cur = q.front();
                q.pop();
                int coloridx = colors[cur] - 'a';
                count[cur][coloridx]++;
                ans = max(ans, count[cur][coloridx]);
                for (int nxt: graph[cur]){
                    removed_edges++;
                    indegrees[nxt]--;
                    // update the color count for the nxt node
                    for(int j = 0; j < 26; j++){
                        count[nxt][j] = max(count[nxt][j], count[cur][j]);
                    }
                    if (indegrees[nxt] == 0){
                        q.push(nxt);
                    }
                }
            }
        }

        if (removed_edges == total_edges){
            return ans;
        }
        return -1;
    }
};