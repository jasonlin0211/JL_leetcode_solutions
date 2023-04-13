class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col, int m, int n, unordered_map<int, unordered_map<int, int>>& seen){
        if (row < 0 || row == m || col < 0 || col == n || grid[row][col] == 0){
            return 1;
        }
        if (seen.count(row) && seen[row].count(col)){
            return 0;
        }
        seen[row][col] = 1;
        int t = 0, b = 0, l = 0, r = 0;
        t = dfs(grid, row-1, col, m, n, seen);
        b = dfs(grid, row+1, col, m, n, seen);
        l = dfs(grid, row, col-1, m, n, seen);
        r = dfs(grid, row, col+1, m, n, seen);
        return t + b + l + r;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        unordered_map<int, unordered_map<int, int>> seen;
        for (int row = 0; row < m; row++){
            for (int col = 0; col < n; col++){
                if (grid[row][col] == 1){
                    ans = dfs(grid, row, col, m, n, seen);
                    return ans;
                }
            }
        }
        return ans;
    }
};