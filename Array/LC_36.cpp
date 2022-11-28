// Written by: Jian-Yuan Lin
// Date: 2022.11.17

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols, blocks;
        for (int row = 0; row < 9; row++){
            for (int col = 0; col < 9; col++){
                if (board[row][col] == '.'){
                    continue;
                }
                char cur = board[row][col];
                if (rows[row].count(cur) || cols[col].count(cur) || blocks[(row/3) * 3 + col/3].count(cur)){
                    return false;
                }
                rows[row].insert(cur);
                cols[col].insert(cur);
                blocks[(row/3) * 3 + col/3].insert(cur);
            }
        }
        return true;
    }
};