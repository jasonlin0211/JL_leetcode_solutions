// Written by: Jian-Yuan Lin
// Date: 2022.11.18

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        vector<vector<int>> atl_seen(m, vector<int>(n, 0));
        vector<vector<int>> pac_seen(m, vector<int>(n, 0));
        // begin DFS from the side to collect all reachable nodes
        for (int row = 0; row < m; row++){
            dfs(heights, row, 0, pac_seen, -1);
            dfs(heights, row, n-1, atl_seen, -1);
        }
        for (int col = 0; col < n; col++){
            dfs(heights, 0, col, pac_seen, -1);
            dfs(heights, m-1, col, atl_seen, -1);
        }
        vector<vector<int>> ans;
        for (int row = 0; row < m; row++){
            for (int col = 0; col < n; col++){
                if (atl_seen[row][col] == 1 && pac_seen[row][col] == 1){
                    ans.push_back({row, col});
                }
            }
        }
        return ans;
    }
private:
    int m, n;

    void dfs(vector<vector<int>>& heights, int row, int col, vector<vector<int>>& seen, int prev){
        if (row < 0 || row == m || col < 0 || col == n || seen[row][col] == 1 || heights[row][col] < prev){
            return;
        }
        seen[row][col] = 1;
        dfs(heights, row+1, col, seen, heights[row][col]);
        dfs(heights, row-1, col, seen, heights[row][col]);
        dfs(heights, row, col+1, seen, heights[row][col]);
        dfs(heights, row, col-1, seen, heights[row][col]);
    }
};