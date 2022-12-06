// Written by: Jian-Yuan Lin
// Date: 2022.12.06

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        // initialization
        dp[1][1] = 1;
        for (int row = 1; row <= m; row++){
            for (int col = 1; col <= n; col++){
                if (row == 1 && col == 1){
                    continue;
                }
                dp[row][col] = dp[row-1][col] + dp[row][col-1];
            }
        }
        return dp[m][n];
    }
};