// Written by: Jian-Yuan Lin
// Date: 2023.01.08

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), t = s3.size();
        if (m + n != t){
            return false;
        }
        vector<vector<bool>> dp(m+1, vector<bool> (n+1, false));
        dp[m][n] = true; // if we can reach the end then it's definitely true
        for (int row = m; row >= 0; row--){
            for (int col = n; col >= 0; col--){
                // make sure don't go out of bound 
                if (row < m && s1[row] == s3[row+col] && dp[row+1][col]){
                    dp[row][col] = true;
                }
                if (col < n && s2[col] == s3[row+col] && dp[row][col+1]){
                    dp[row][col] = true;
                }
            }
        }

        return dp[0][0];
    }
};



class Solution {
public:
    bool dp(int i, int j, string& s1, string& s2, string& s3, unordered_map<int, unordered_map<int, bool>>& mem){
        if (i == s1.size() && j == s2.size()){
            return true;
        }
        if (mem.count(i) && mem[i].count(j)){
            return mem[i][j];
        }
        mem[i][j] = false;
        if (s1[i] == s3[i+j] && dp(i+1, j, s1, s2, s3, mem)){
            mem[i][j] = true;
        }
        if (s2[j] == s3[i+j] && dp(i, j+1, s1, s2, s3, mem)){
            mem[i][j] = true;
        }
        return mem[i][j];
    }
    bool isInterleave(string s1, string s2, string s3) {
        // try top down DP + memoization first
        unordered_map<int, unordered_map<int, bool>> mem;
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()){
            return false;
        }
        return dp(0, 0, s1, s2, s3, mem);
    }
};