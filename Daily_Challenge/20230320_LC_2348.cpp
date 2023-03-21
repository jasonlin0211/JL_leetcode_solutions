class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int i = 0, n = nums.size();

        while (i < n){
            if (nums[i] == 0){
                int j = i + 1;
                while(j < n && nums[j] == 0){
                    j++;
                }
                long long l = j - i + 1;
                ans += (l * (l-1))/2;
                i = j;
            }
            i++;
        }
        return ans;
    }
};