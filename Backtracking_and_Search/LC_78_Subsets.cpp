// Written by: Jian-Yuan Lin
// Date: 2022.11.19

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        for (int l = 0; l <= n; l++){
            vector<int> curr;
            dfs(nums, 0, l, curr, ans);
        }
        return ans;
    }
private:
    void dfs(vector<int>& nums, int start, int length, vector<int>& curr, vector<vector<int>> & ans){
        if (curr.size() == length){
            ans.push_back(curr);
            return;
        }
        for(int i = start; i < nums.size(); i++){
            curr.push_back(nums[i]);
            dfs(nums, i+1, length, curr, ans);
            curr.pop_back();
        }
    }
};