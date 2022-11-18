// Written by: Jian-Yuan Lin
// Date: 2022.11.17

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // based on the two sum sorted!
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 3){
            return ans;
        }
        sort(nums.begin(), nums.end());
        // this is actually tricky, don't under estimate it
        for (int i = 0; i < n-2; i++){
            int target = -nums[i];
            if (target < 0){
                continue;
            }
            // avoid duplicate calculation!
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            int j = i + 1, k = n - 1;
            while (j < k){
                int cur = nums[j] + nums[k];
                if (cur > target){
                    k--;
                }
                else if(cur < target){
                    j++;
                }
                else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    // use two while loop to make sure j and k not going to be repeated
                    while (j < k  && nums[j] == nums[j+1]){
                        j++;
                    }
                    j++;
                    while (j < k && nums[k] == nums[k-1]){
                        k--;
                    }
                    k--;
                }
            }
        }
        return ans;
    }
};