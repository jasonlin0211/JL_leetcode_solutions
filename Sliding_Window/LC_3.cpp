// Written by: Jian-Yuan Lin
// Date: 2022.11.28

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        int l = 0, r = 0, n = s.size();
        int max_len = 0;
        while (r < n){
            seen[s[r]]++;            
            if (seen[s[r]] > 1){
                while (l < r && seen[s[r]] > 1){
                    seen[s[l]]--;
                    l += 1;
                }
            }
            int cur_len = r-l+1;
            if (cur_len > max_len){
                max_len = cur_len;
            }
            r++;
        }
        return max_len;
    }
};