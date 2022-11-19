// Written by: Jian-Yuan Lin
// Date: 2022.11.18

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // standard BFS problem!
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        vector<vector<int>> seen(m, vector<int>(n, 0));
        for (int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if (grid[row][col] == 2){
                    q.push({row, col});
                    seen[row][col] = 1;
                }
                else if (grid[row][col] == 1){
                    fresh++;
                }
            }
        }
        if (fresh == 0){
            return 0;
        }
        int steps = 0;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                int cur_row = q.front().first;
                int cur_col = q.front().second;
                q.pop();
                for (int j = 0; j < 4; j++){
                    int nxt_row = cur_row + dirs[j][0], nxt_col = cur_col + dirs[j][1];
                    if (nxt_row < 0 || nxt_row == m || nxt_col < 0 || nxt_col == n || seen[nxt_row][nxt_col] == 1){
                        continue;
                    }
                    if (grid[nxt_row][nxt_col] == 1){
                        seen[nxt_row][nxt_col] = 1;
                        fresh--;
                        grid[nxt_row][nxt_col] = 2;
                        q.push({nxt_row, nxt_col});
                    }
                    if (fresh == 0){
                        return steps + 1;
                    }
                }
            }
            steps++;
        }
        return -1;
           
    }
};