// Written by: Jian-Yuan Lin
// Date: 2022.11.19

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(candidates, target, 0, curr, ans);
        return ans;
    }
private:
    void dfs(vector<int>& nums, int target, int start, vector<int>& curr, vector<vector<int>>& ans){
        if (target == 0){
            ans.push_back(curr);
            return;
        }
        if (target < 0){
            return;
        }
        for (int i = start; i < nums.size(); i++){
            if (i != start && nums[i] == nums[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            dfs(nums, target - nums[i], i+1, curr, ans);
            curr.pop_back();
        }
    }
};