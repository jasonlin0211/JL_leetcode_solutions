// Written by: Jian-Yuan Lin
// Date: 2022.12.06

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;
        for (int i = nums.size()-1; i >= 0; i--){
            if (i + nums[i] >= goal){
                goal = i;
            }
        }
        return goal == 0;
    }
};


class Solution {
public:
    // top down will TLE
    bool dfs(vector<int>& nums, int i, int n, unordered_map<int,int>& mem){
        if (i >= n-1){
            return true;
        }
        if (i + nums[i] >= n-1){
            return true;
        }
        if (mem.count(i)){
            return mem[i];
        }
        mem[i] = false;

        for(int j = 1; j <= nums[i]; j++){
            if (dfs(nums, i + j, n, mem)){
                mem[i] = true;
                break;
            }
        }
        return mem[i];
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mem;
        return dfs(nums, 0, n, mem);
    }
};