// Written by: Jian-Yuan Lin
// Date: 2022.12.06

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // practice bit manipulation
        int n = nums.size();
        int ans = n;
        // a xor a = 0, a xor 0 = a
        for (int i = 0; i < n; i++){
            ans ^= (i ^ nums[i]);
        }
        return ans;
    }
};