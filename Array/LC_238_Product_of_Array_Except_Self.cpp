// Written by: Jian-Yuan Lin
// Date: 2022.11.17

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // O(1) space complexity version
        int n = nums.size();
        vector<int> ans(n, 0);
        ans[0] = 1;
        for (int i = 1; i < n; i++){
            ans[i] = ans[i-1] * nums[i-1];
        }
        int r = 1;
        for (int i = n-1; i >= 0; i--){
            ans[i] *= r;
            r *= nums[i];
        }
        return ans;
        /*
        int n = nums.size();
        vector<int> l(n, 1), r(n, 1);
        for (int i = 1; i < n; i++){
            l[i] = l[i-1] * nums[i-1];
        }
        for (int i = n-2; i >= 0; i--){
            r[i] = r[i+1] * nums[i+1];
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++){
            ans[i] = l[i] * r[i];
        }
        return ans;
        */
    }
};