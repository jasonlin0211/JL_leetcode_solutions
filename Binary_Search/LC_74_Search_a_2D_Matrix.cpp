// Written by: Jian-Yuan Lin
// Date: 2022.11.19

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> first_col;
        for (int row = 0; row < m; row++){
            first_col.push_back(matrix[row][0]);
        }
        int to_search_row = 0;
        to_search_row = find_row(first_col, target);
        if (to_search_row == -1){
            return false;
        }
        return find_exist(matrix[to_search_row], target);
    }
private:
    // find the upper bound, if return -1 means even the first value in the first column is bigger than target, not existent!
    int find_row(vector<int>& nums, int val){
        int l = 0, r = nums.size();
        while (l < r){
            int mid = l + (r-l)/2;
            if (nums[mid] > val){
                r = mid;
            }
            else{
                l = mid + 1;
            } 
        }
        return l - 1;
    }
    // find if the val exists in the nums
    bool find_exist(vector<int>& nums, int val){
         int l = 0, r = nums.size();
        while (l < r){
            int mid = l + (r-l)/2;
            if (nums[mid] == val){
                return true;
            }
            else if (nums[mid] > val){
                r = mid;
            }
            else{
                l = mid + 1;
            } 
        }
        return false;
    }
};
