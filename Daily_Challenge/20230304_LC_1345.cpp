class Solution {
public:
    int minJumps(vector<int>& arr) {
        // BFS solution
        // build graph
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < arr.size(); i++){
            graph[arr[i]].push_back(i);
        }
        unordered_set<int> seen;
        queue<int> q;
        q.push(0);
        seen.insert(0);
        int steps = 0;
        int n = arr.size();
        while (!q.empty()){
            int size = q.size();
            for (int iter = 0; iter < size; iter++){
                int cur = q.front();
                q.pop();
                //cout << cur << endl;
                if (cur == n - 1){
                    return steps;
                }
                // explore cur-1 and cur+1
                vector<int> nei = {cur-1, cur+1};
                for (int nxt: nei){
                    if (nxt >= 0 && nxt < n && !seen.count(nxt)){
                        q.push(nxt);
                        seen.insert(nxt);
                    }
                }
                // explore the same value indices
                for (int nxt: graph[arr[cur]]){
                    //cout << nxt << endl;
                    if (!seen.count(nxt)){
                        q.push(nxt);
                        seen.insert(nxt);
                    }
                }
                graph[arr[cur]].clear();
            }
            steps++;
        }

        return -1;
    }
};