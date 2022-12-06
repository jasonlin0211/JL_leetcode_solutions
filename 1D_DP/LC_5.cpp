// Written by: Jian-Yuan Lin
// Date: 2022.12.06

class Solution {
public:
    string longestPalindrome(string s) {
        // begin from the middle and expand
        int n = s.size();
        string ans;
        int ans_len = 0;
        for (int i = 0; i < n; i++){
            // odd length Palindrome
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]){
                if (r - l + 1 > ans_len){
                    ans_len = r - l + 1;
                    ans = s.substr(l, ans_len);
                }
                l--;
                r++;
            }
            // even length Palindrome
            l = i;
            r = i+1;
            while (l >= 0 && r < n && s[l] == s[r]){
                if (r - l + 1 > ans_len){
                    ans_len = r - l + 1;
                    ans = s.substr(l, ans_len);
                }
                l--;
                r++;
            }
        }
        
        return ans;
    }
};