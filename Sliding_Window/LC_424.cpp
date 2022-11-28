// Written by: Jian-Yuan Lin
// Date: 2022.11.28

class Solution {
public:
    int characterReplacement(string s, int k) {
        // two pointers
        int l = 0, r = 0;
        int ans = 0;
        int max_count = 0;
        unordered_map<char, int> count;
        while (r < s.size()){
            count[s[r]]++;
            max_count = max(max_count, count[s[r]]);
            // if current substring length is greater than max count + k, need to shift the left pointer!
            if ((r-l+1) > max_count + k){
                count[s[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};