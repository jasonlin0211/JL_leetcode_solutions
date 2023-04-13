class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, int m, int n){
        if (row < 0 || row == m || col < 0 || col == n){
            return;
        }
        if (grid[row][col] != 1){
            return;
        }
        grid[row][col] = -1;
        dfs(grid, row+1, col, m, n);
        dfs(grid, row-1, col, m, n);
        dfs(grid, row, col+1, m, n);
        dfs(grid, row, col-1, m, n);
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        // mark the 1 that can be reached from the boundary
        for (int row = 0; row < m; row++){
            if (grid[row][0] == 1){
                dfs(grid, row, 0, m, n);
            }
            if (grid[row][n-1] == 1){
                dfs(grid, row, n-1, m, n);
            }
        }
        for (int col = 0; col < n; col++){
            if (grid[0][col] == 1){
                dfs(grid, 0, col, m, n);
            }
            if (grid[m-1][col] == 1){
                dfs(grid, m-1, col, m, n);
            }
        }
        // count the answer
        for (int row = 0; row < m; row++){
            for (int col = 0; col < n; col++){
                if (grid[row][col] == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};