// Written by: Jian-Yuan Lin
// Date: 2023.01.03

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // minheap, store (t, row, col)
        pq.push({grid[0][0], 0, 0});
        vector<vector<bool>> seen(n, vector<bool> (n, false));
        seen[0][0] = true;
        // unordered_set<pair<int, int>> seen; this will not work since there's no default hashing function for pair in C++
        // seen.insert({0, 0});
        
        while (!pq.empty()){
            int t = pq.top()[0], cur_row = pq.top()[1], cur_col = pq.top()[2];
            pq.pop();
            if (cur_row == n-1 && cur_col == n-1){
                return t;
            }
            for (vector<int> dir: dirs){
                int nxt_row = cur_row + dir[0], nxt_col = cur_col + dir[1];
                if (nxt_row < 0 || nxt_row == n || nxt_col < 0 || nxt_col == n || seen[nxt_row][nxt_col] == true){
                    continue;
                }
                seen[nxt_row][nxt_col] = true;
                pq.push({max(t, grid[nxt_row][nxt_col]), nxt_row, nxt_col});
            }
        }
        return -1;

    }
};