// Written by: Jian-Yuan Lin
// Date: 2022.12.04

class Solution {
public:
    bool dfs(int start, int c, vector<int>& color, vector<vector<int>>& graph){
        color[start] = c;
        for (int i = 0; i < graph[start].size(); i++){
            int nxt = graph[start][i];
            if (color[nxt] == c || (color[nxt] == 0 && !dfs(nxt, -c, color, graph))){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        for (int i = 0; i < n; i++){
            if (color[i] == 0){
                if (!dfs(i, 1, color, graph)){
                    return false;
                }
            }
        }
        return true;
    }
};