// Written by: Jian-Yuan Lin
// Date: 2023.01.09

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // add padding to the nums (1, nums, 1)
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        // c[i][j] = max points using nums[i:j+1]
        vector<vector<int>> c(n+2, vector<int> (n+2, 0));
        // very tricky, find the best split k!
        // build from shorter interval to longer interval
        for (int l = 1; l <= n; l++){
            for (int i = 1; i <= n-l+1; i++){
                int j = i+l-1; // fixed end due to fix length
                // find the best split point k
                for (int k = i; k <= j; k++){
                    c[i][j] = max(c[i][j], c[i][k-1] + nums[i-1] * nums[k] * nums[j+1] + c[k+1][j]);
                }
            }
        }
        return c[1][n];
    }
};