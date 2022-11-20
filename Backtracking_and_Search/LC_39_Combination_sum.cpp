// Written by: Jian-Yuan Lin
// Date: 2022.11.19

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(candidates, 0, target, curr, ans);
        return ans;   
    }
private:
    void dfs(vector<int>& nums, int start, int target, vector<int>& curr, vector<vector<int>>& ans){
        if (target == 0){
            ans.push_back(curr);
            return;
        }
        if (target < 0){
            return;
        }
        for (int i = start; i < nums.size(); i++){
            curr.push_back(nums[i]);
            dfs(nums, i, target - nums[i], curr, ans);
            curr.pop_back();
        }
    }
};