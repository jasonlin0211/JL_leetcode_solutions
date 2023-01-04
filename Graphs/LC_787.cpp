// Written by: Jian-Yuan Lin
// Date: 2023.01.03

class Solution {
public:
    void print_dp(vector<int> dp){
        for (int val: dp){
            cout << val << " ";
        }
        cout << endl;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // bellman-ford algorithm
        unordered_map<int, vector<pair<int, int>>> graph;
        for (vector<int> f: flights){
            int start = f[0], end = f[1], cost = f[2];
            graph[start].push_back({end, cost});
        }
        vector<int> dp(n, INT_MAX);
        dp[src] = 0;

        for (int i = 0; i <= k; i++){
            vector<int> nxt_dp = dp;
            for (auto pair: graph){
                int node = pair.first;
                if (dp[node] == INT_MAX){
                    continue;
                }
                // be extra careful here!
                for (auto p: pair.second){
                    int nxt = p.first, cost = p.second;
                    if (nxt_dp[nxt] > dp[node] + cost){
                        nxt_dp[nxt] = dp[node] + cost;
                    }
                }
            }
            dp = nxt_dp;
            //print_dp(dp);
        }
        
        if (dp[dst] == INT_MAX){
            return -1;
        }
        return dp[dst];
    }
};