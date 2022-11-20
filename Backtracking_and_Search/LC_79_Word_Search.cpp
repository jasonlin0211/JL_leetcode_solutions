// Written by: Jian-Yuan Lin
// Date: 2022.11.19

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for (int row = 0; row < m; row++){
            for (int col = 0; col < n; col++){
                if (dfs(board, row, col, 0, word)){
                    return true;
                }
            }
        }
        return false;
    }
private:
    int m, n;
    bool dfs(vector<vector<char>>& board, int row, int col, int i, string word){
        if (i == word.size()){
            return true;
        }
        if (row < 0 || row == m || col < 0 || col == n || board[row][col] != word[i]){
            return false;
        }
        char c = board[row][col];
        board[row][col] = '#';
        bool l = false, r = false, t = false, b = false;
        l = dfs(board, row, col - 1, i+1, word);
        r = dfs(board, row, col + 1, i+1, word);
        t = dfs(board, row - 1, col, i+1, word);
        b = dfs(board, row + 1, col, i+1, word);
        board[row][col] = c;
        return l || r || t || b;
    }
};