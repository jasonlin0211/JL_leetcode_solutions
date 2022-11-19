// Written by: Jian-Yuan Lin
// Date: 2022.11.18

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        // collect the 'O' from the side
        for (int row = 0; row < m; row++){
            if (board[row][0] == 'O'){
                dfs(board, row, 0, '#');            
            }
            if (board[row][n-1] == 'O'){
                dfs(board, row, n-1, '#');
            }
        }
        for (int col = 0; col < n; col++){
            if (board[0][col] == 'O'){
                dfs(board, 0, col, '#');
            }
            if (board[m-1][col] == 'O'){
                dfs(board, m-1, col, '#');
            }
        }
        for (int row = 0; row < m; row++){
            for (int col = 0; col < n; col++){
                if (board[row][col] == 'O'){
                    board[row][col] = 'X';
                }
                if (board[row][col] == '#'){
                    board[row][col] = 'O';
                }
            }
        }
    }
private:
    int m, n;

    void dfs(vector<vector<char>>& board, int row, int col, char val){
        if (row < 0 || row == m || col < 0 || col == n || board[row][col] != 'O'){
            return;
        }
        board[row][col] = val;
        dfs(board, row+1, col, val);
        dfs(board, row-1, col, val);
        dfs(board, row, col+1, val);
        dfs(board, row, col-1, val);
    }
};