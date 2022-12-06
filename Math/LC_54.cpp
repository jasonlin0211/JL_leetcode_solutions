// Written by: Jian-Yuan Lin
// Date: 2022.12.06

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l = 0, r = matrix[0].size(), t = 0, b = matrix.size();
        vector<int> ans;
        while (l < r && t < b){
            // top row
            for (int i = l; i < r; i++){
                ans.push_back(matrix[t][i]);
            }
            t++;
            // right col
            for (int i = t; i < b; i++){
                ans.push_back(matrix[i][r-1]);
            }
            r--;
            // check if overlapped, break
            if (!(l < r && t < b)){
                break;
            }
            // bottom row
            for (int i = r - 1; i >= l; i--){
                ans.push_back(matrix[b-1][i]);
            }
            b--;
            // left col
            for (int i = b-1; i >= t; i--){
                ans.push_back(matrix[i][l]);
            }
            l++;
        }
        return ans;
    }
};