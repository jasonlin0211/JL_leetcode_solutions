class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int maxdays = days.back();
        vector<int> dp(maxdays + 1, 0);
        unordered_set<int> seen(days.begin(), days.end());
        for (int d = 1; d <= maxdays; d++){
            if (!seen.count(d)){
                dp[d] = dp[d-1];
            }
            else{
                dp[d] = dp[d-1] + costs[0];
                dp[d] = min(dp[d], dp[max(0, d-7)] + costs[1]);
                dp[d] = min(dp[d], dp[max(0, d-30)] + costs[2]);
            }
        }
    
        return dp[maxdays];
    }
};