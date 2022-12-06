// Written by: Jian-Yuan Lin
// Date: 2022.12.06

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // binary search based O(nlogn) solution
        int n = nums.size();
        vector<int> LIS;
        for (int i = 0; i < n; i++){
            auto it = lower_bound(LIS.begin(), LIS.end(), nums[i]);
            if (it == LIS.end()){
                LIS.push_back(nums[i]);
            }
            else{
                *it = nums[i];
            }
        }
        return LIS.size();
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // textbook O(n^2) solution
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};