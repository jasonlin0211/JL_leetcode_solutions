// Written by: Jian-Yuan Lin
// Date: 2022.12.06

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // need to consider the prev min and prev max
        int n = nums.size();
        vector<int> dp_min(n, 0), dp_max(n, 0);
        dp_min[0] = nums[0];
        dp_max[0] = nums[0];

        for (int i = 1; i < n; i++){
            dp_max[i] = max(nums[i], max(nums[i] * dp_max[i-1], nums[i] * dp_min[i-1]));
            dp_min[i] = min(nums[i], min(nums[i] * dp_max[i-1], nums[i] * dp_min[i-1]));
        }
        auto it_max = max_element(dp_max.begin(), dp_max.end()), it_max2 = max_element(dp_min.begin(), dp_min.end());
        return max(*it_max, *it_max2);
    }
};