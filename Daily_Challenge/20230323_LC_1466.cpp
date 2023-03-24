class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, unordered_map<int, bool>> seen;
        for (vector<int> c: connections){
            seen[c[0]][c[1]] = true;
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        queue<int> q;
        q.push(0);
        unordered_set<int> visited;
        visited.insert(0);
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            for (int iter = 0; iter < size; iter++){
                int cur = q.front();
                q.pop();
                for (int nxt : graph[cur]){
                    if (visited.count(nxt)){
                        continue;
                    }
                    if (seen.count(cur) && seen[cur].count(nxt)){
                        ans += 1;
                    }
                    visited.insert(nxt);
                    q.push(nxt);
                }
            }
        }
        return ans;
    }
};