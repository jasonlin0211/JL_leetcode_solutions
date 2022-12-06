// Written by: Jian-Yuan Lin
// Date: 2022.12.05

class Solution {
public:
    string alienOrder(vector<string>& words) {
        // classical problem for topology sorting
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> indegree;
        // build the indegree table
        for (string word: words){
            for(char c: word){
                indegree[c] = 0;
            }
        }
        // build graph and count the total edges
        int total_edges = 0;
        for(int i = 0; i < words.size() - 1; i++){
            string first = words[i], second = words[i+1];
            for (int idx = 0; idx < min(first.size(), second.size()); idx++){
                if (first[idx] != second[idx]){
                    graph[first[idx]].push_back(second[idx]);
                    total_edges++;
                    indegree[second[idx]]++;
                    break;
                }
            }
            // special case here: second string is the prefix of first string
            if (first.size() > second.size() && first.substr(0, second.size()) == second){
                return "";
            }
        }
        // start the BFS for topology sorting
        queue<char> q;
        
        for (auto item: indegree){
            if (item.second == 0){
                q.push(item.first);
            }
        }
        int removed_edges = 0;
        string ans = "";
        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                char cur = q.front();
                q.pop();
                ans += cur;
                for (int nxt: graph[cur]){
                    indegree[nxt]--;
                    removed_edges++;
                    if (indegree[nxt] == 0){
                        q.push(nxt);
                    }
                }
            }
        }
        if (removed_edges == total_edges){
            return ans;
        }
        return "";
    }
};