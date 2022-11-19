// Written by: Jian-Yuan Lin
// Date: 2022.11.18

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // topology sorting using BFS
        int n = numCourses;
        vector<int> indegrees(n, 0);
        int total_edges = 0, removed_edges = 0;
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < prerequisites.size(); i++){
            int cur = prerequisites[i][1], prev = prerequisites[i][0];
            indegrees[cur]++;
            graph[prev].push_back(cur);
            total_edges++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++){
            if (indegrees[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            for(int nxt: graph[cur]){
                removed_edges++;
                indegrees[nxt]--;
                if (indegrees[nxt] == 0){
                    q.push(nxt);
                }
            }
        }
        if (removed_edges == total_edges){
            reverse(ans.begin(), ans.end());
            return ans;
        }
        return {};
    }
};