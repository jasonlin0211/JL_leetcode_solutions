// Written by: Jian-Yuan Lin
// Date: 2022.12.05

class Solution {
public:

    int rob1(vector<int>& nums) {
        int n = nums.size();
        if (n == 1){
            return nums[0];
        }
        vector<int> dp(n+1, 0);
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1){
            return nums[0];
        }
        vector<int> part1, part2;
        for(int i = 0; i < n; i++){
            if (i == 0){
                part1.push_back(nums[i]);
            }
            else if (i == n-1){
                part2.push_back(nums[i]);
            }
            else{
                part1.push_back(nums[i]);
                part2.push_back(nums[i]);
            }
        }
        return max(rob1(part1), rob1(part2));
    }
};