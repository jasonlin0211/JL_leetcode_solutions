// Written by: Jian-Yuan Lin
// Date: 2023.01.03

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int num: nums){
            total += num;
        }
        if (total % 2){
            return false;
        }
        int target = total / 2;
        // similar to coin change problem
        vector<int> dp(total + 1, 0);
        dp[0] = 1;
        // do it in reverse way to void the temp list and swap, use the entire total since we might exceed target
        for (int num: nums){
            for (int i = total; i >= 0; i--){
                if (dp[i]){
                    dp[i+num] = 1;
                }
                if (dp[target]){
                    return true;
                }
            }
        }
        return false;
    }
};