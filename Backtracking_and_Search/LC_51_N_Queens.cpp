// Written by: Jian-Yuan Lin
// Date: 2022.11.19

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> curr;
        dfs(0, n, curr, ans);
        return ans;
    }
private:
    unordered_set<int> used_col, used_diag, used_anti_diag;
    void dfs(int row, int n, vector<string>& curr, vector<vector<string>>& ans){
        if (row == n){
            ans.push_back(curr);
            return;
        }
        for(int col = 0; col < n; col++){
            int diag = row - col, anti_diag = row + col;
            if (used_col.count(col) || used_diag.count(diag) || used_anti_diag.count(anti_diag)){
                continue;
            }
            string temp = string(col, '.') + 'Q' + string(n-col-1, '.');
            used_col.insert(col);
            used_diag.insert(diag);
            used_anti_diag.insert(anti_diag);
            curr.push_back(temp);
            dfs(row + 1, n, curr, ans);
            curr.pop_back();
            used_col.erase(col);
            used_diag.erase(diag);
            used_anti_diag.erase(anti_diag);

        }
    }
};