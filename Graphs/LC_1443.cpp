// Written by: Jian-Yuan Lin
// Date: 2023.01.10

class Solution {
public:
    int dfs(int prev, int curr, unordered_map<int, vector<int>>& graph, vector<bool>& item){
        int total_time = 0, child_time = 0;
        for (int nxt: graph[curr]){
            if (nxt == prev){
                continue;
            }
            child_time = dfs(curr, nxt, graph, item);
            if (child_time || item[nxt]){
                total_time += child_time + 2;
            }
        }
        return total_time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // build graph
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        return dfs(-1, 0, graph, hasApple);
    }
};