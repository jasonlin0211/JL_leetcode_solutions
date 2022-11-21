// Written by: Jian-Yuan Lin
// Date: 2022.11.20

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        int start_row = entrance[0], start_col = entrance[1];
        q.push(make_pair(start_row, start_col));
        maze[start_row][start_col] = '+';
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool found = false;
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            for (int k = 0; k < size; k++){
                int cur_row = q.front().first, cur_col = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++){
                    int nxt_row = cur_row + dirs[i][0], nxt_col = cur_col + dirs[i][1];
                    if (nxt_row >= 0 && nxt_row < m && nxt_col >= 0 && nxt_col < n && maze[nxt_row][nxt_col] == '.'){
                        if (nxt_row == 0 || nxt_row == m-1 || nxt_col == 0 || nxt_col == n-1){
                            return steps + 1;
                        }
                        maze[nxt_row][nxt_col] = '+';
                        q.push(make_pair(nxt_row, nxt_col));
                    } 
                }
            }
            steps++;
        }
        return -1;
    }
};