// Written by: Jian-Yuan Lin
// Date: 2022.12.06

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++){
            // odd length Palindrome
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]){
                ans++;
                l--;
                r++;
            }
            // even length Palindrome
            l = i;
            r = i+1;
            while (l >= 0 && r < n && s[l] == s[r]){
                ans++;
                l--;
                r++;
            }
        }
        return ans;
    }
};