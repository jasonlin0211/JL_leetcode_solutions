// Written by: Jian-Yuan Lin
// Date: 2022.11.17

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if (grid[row][col] == '1'){
                    ans++;
                    dfs(grid, row, col, m, n);
                }
            }
        }
        return ans;
    }
private:
    void dfs(vector<vector<char>>& grid, int row, int col, int m, int n){
        if (row < 0 || row == m || col < 0 || col == n || grid[row][col] != '1'){
            return;
        }
        grid[row][col] = 'X';
        dfs(grid, row+1, col, m, n);
        dfs(grid, row-1, col, m, n);
        dfs(grid, row, col+1, m, n);
        dfs(grid, row, col-1, m, n);
    }
};