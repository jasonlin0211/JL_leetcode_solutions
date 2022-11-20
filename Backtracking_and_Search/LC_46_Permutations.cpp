// Written by: Jian-Yuan Lin
// Date: 2022.11.19

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> used(n, 0);
        vector<int> curr;
        dfs(nums, curr, used, ans);
        return ans;
    }
private:
    void dfs(vector<int>& nums, vector<int>& curr, vector<int>& used, vector<vector<int>>& ans){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (used[i]){
                continue;
            }
            used[i] = 1;
            curr.push_back(nums[i]);
            dfs(nums, curr, used, ans);
            curr.pop_back();
            used[i] = 0;
        }
    }
};