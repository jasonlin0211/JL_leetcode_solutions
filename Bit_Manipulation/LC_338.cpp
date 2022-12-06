// Written by: Jian-Yuan Lin
// Date: 2022.12.06

class Solution {
public:
    int count_bit(int n){
        int ans = 0;
        while (n){
            ans++;
            n = n & (n-1);
        }
        return ans;
    }
    vector<int> countBits(int n) {
        // DP solution is very smart!
        vector<int> dp(n+1, 0);
        int offset = 1;
        for (int i = 1; i <= n; i++){
            // advanced to the next bit
            if (offset * 2 == i){
                offset = i;
            }
            dp[i] = 1 + dp[i-offset];
        }
        return dp;
        /* using LC 191 solution
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            ans.push_back(count_bit(i));
        }
        return ans;*/
    }
};