// Written by: Jian-Yuan Lin
// Date: 2022.12.06

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0'){
            return 0;
        }
        int n = s.size();
        vector<int> dp(n+1, 0); // dp(i) stands for the ways to decode include the first ith chars
        // initialization
        dp[0] = 1;
        dp[1] = 1; 

        for (int i = 2; i <= n; i++){
            // include one digit
            int one = stoi(s.substr(i-1, 1));
            if (one >= 1 && one <= 9){
                dp[i] += dp[i-1];
            }
            // include two digits
            int two = stoi(s.substr(i-2, 2));
            if (two >= 10 && two <= 26){
                dp[i] += dp[i-2];
            }
        }

        return dp[n];
    }
};