// Written by: Jian-Yuan Lin
// Date: 2022.12.06

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // this is a very interesting problem if we want to do it in O(1) space
        // use the first row and col to indicate whether this row or col needs to be zero or not
        // first scan the first row and first col to make sure whether we need to set the first row and first col all to zero!
        int m = matrix.size(), n = matrix[0].size();
        bool first_row_all_zero = false, first_col_all_zero = false;

        for (int col = 0; col < n; col++){
            if (matrix[0][col] == 0){
                first_row_all_zero = true;
                break;
            }
        }

        for (int row = 0; row < m; row++){
            if (matrix[row][0] == 0){
                first_col_all_zero = true;
                break;
            }
        }
        
        // use first row and first col to mark which row and col needs to be zeroes
        for (int row = 1; row < m; row++){
            for (int col = 1; col < n; col++){
                if (matrix[row][col] == 0){
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }
        for (int row = 1; row < m; row++){
            for (int col = 1; col < n; col++){
                if (matrix[row][0] == 0 || matrix[0][col] == 0){
                    matrix[row][col] = 0;
                }
            }
        }
        if (first_row_all_zero){
            for (int col = 0; col < n; col++){
                matrix[0][col] = 0;
            }
        }
        if (first_col_all_zero){
            for (int row = 0; row < m; row++){
                matrix[row][0] = 0;
            }
        }

    }
};