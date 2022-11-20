// Written by: Jian-Yuan Lin
// Date: 2022.11.19

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        int n = nums.size();
        for (int l = 0; l <= n; l++){
            dfs(nums, curr, 0, l, ans);
        }
        return ans;
    }
private:
    void dfs(vector<int>& nums, vector<int>& curr, int start, int l, vector<vector<int>>& ans){
        if (curr.size() == l){
            ans.push_back(curr);
            return;
        }
        for(int i = start; i < nums.size(); i++){
            if (i != start && nums[i] == nums[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            dfs(nums, curr, i+1, l, ans);
            curr.pop_back();
        }
    }
};