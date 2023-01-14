// Written by: Jian-Yuan Lin
// Date: 2023.01.11

class Solution {
public:
    vector<int> dfs (int prev, int node, unordered_map<int, vector<int>>& graph, vector<vector<int>>& cnt, string& labels){
        vector<int> ans(26, 0);
        // for every node, record the count of 26 chars, and then add the node it self, similar to post order traversal
        for (int nxt: graph[node]){
            if (nxt == prev){
                continue;
            }
            vector<int> temp = dfs(node, nxt, graph, cnt, labels);
            for (int j = 0; j < 26; j++){
                ans[j] += temp[j];
            }
        }
        ans[labels[node] - 'a']++;
        cnt[node] = ans;
        return ans;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, vector<int>> graph;
        for (vector<int> e: edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<vector<int>> cnt(n, vector<int> (26, 0));
        dfs(-1, 0, graph, cnt, labels);
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++){
            ans[i] = cnt[i][labels[i] - 'a'];
        }
        return ans;
    }
};