// Written by: Jian-Yuan Lin
// Date: 2022.11.18

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size();
        int steps = 1;
        queue<pair<int, int>> q;
        vector<vector<int>> seen(m, vector<int>(n, 0));
        for (int row = 0; row < m; row++){
            for (int col = 0; col < n; col++){
                if (rooms[row][col] == 0){
                    q.push({row, col});
                    seen[row][col] = 1;
                }
            }
        }
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                int cur_row = q.front().first;
                int cur_col = q.front().second;
                q.pop();
                for (int j = 0; j < 4; j++){
                    int nxt_row = cur_row + dirs[j][0];
                    int nxt_col = cur_col + dirs[j][1];
                    if (nxt_row < 0 || nxt_row == m || nxt_col < 0 || nxt_col == n || seen[nxt_row][nxt_col] || rooms[nxt_row][nxt_col] == -1){
                        continue;
                    }
                    seen[nxt_row][nxt_col] = 1;
                    rooms[nxt_row][nxt_col] = steps;
                    q.push({nxt_row, nxt_col});
                }
            }
            steps++;
        }   
    }
};