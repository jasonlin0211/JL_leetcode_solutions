class Solution {
public:
    int dfs(int row, int col, int m, int n, vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        if (row < 0 || row == m || col < 0 || col == n || grid2[row][col] == 0){
            return 1;
        }
        grid2[row][col] = 0; // mark as visited
        int result = 1;
        if (grid1[row][col] == 0){
            result = 0; // note you can't return just here, you need to finish the whole dfs!
        }
        result &= dfs(row+1, col, m, n, grid1, grid2);
        result &= dfs(row-1, col, m, n, grid1, grid2);
        result &= dfs(row, col+1, m, n, grid1, grid2);
        result &= dfs(row, col-1, m, n, grid1, grid2);
        return result;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        int ans = 0;
        unordered_map<int, unordered_map<int, int>> seen;
        for (int row = 0; row < m; row++){
            for (int col = 0; col < n; col++){
                if (grid2[row][col] == 1){
                    ans+= dfs(row, col, m, n, grid1, grid2);
                }
            }
        }
        return ans;
    }
};