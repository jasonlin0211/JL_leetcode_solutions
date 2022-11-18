// Written by: Jian-Yuan Lin
// Date: 2022.11.17

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        m = grid.size(), n = grid[0].size();

        for (int row = 0; row < m; row++){
            for (int col = 0; col < n; col++){
                if (grid[row][col] == 1){
                    ans = max(ans, dfs(grid, row, col));
                }
            }
        }
        return ans;
    }
private:
    int m, n;

    int dfs(vector<vector<int>>& grid, int row, int col){
        if (row < 0 || row == m || col < 0 || col == n || grid[row][col] != 1){
            return 0;
        }
        grid[row][col] = 0;
        int ans = 1;
        int l = 0, r = 0, t = 0, b = 0;
        l = dfs(grid, row, col-1);
        r = dfs(grid, row, col+1);
        t = dfs(grid, row-1, col);
        b = dfs(grid, row+1, col);
        return 1 + l + r + t + b;
    }
};