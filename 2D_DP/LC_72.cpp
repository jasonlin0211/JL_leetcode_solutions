// Written by: Jian-Yuan Lin
// Date: 2023.01.07

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        // dp[i][j] stands for the number of methods using i chars from word1 
        // and j chars from word2
        vector<vector<int>> dp (m+1, vector<int> (n+1, 0));
        // initialization, entirely not using one string
        for (int row = 1; row <= m; row++){
            dp[row][0] = row;
        }
        for (int col = 1; col <= n; col++){
            dp[0][col] = col;
        }
        for (int row = 1; row <= m; row++){
            for (int col = 1; col <= n; col++){
                // two chars are the same, check the previous answer
                if (word1[row-1] == word2[col-1]){
                    dp[row][col] = dp[row-1][col-1];
                }
                // choose from delete, insert, replace
                else{
                    dp[row][col] =  1 + min(dp[row-1][col], min(dp[row][col-1], dp[row-1][col-1]));
                }
            }
        }
        return dp[m][n];

    }
};