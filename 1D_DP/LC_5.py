# Written by: Jian-Yuan Lin
# Date: 2022.12.06

class Solution:
    def longestPalindrome(self, s: str) -> str:
        # begin from the middle and expand
        ans = ""
        ans_len = 0
        n = len(s)
        for i in range(n):
            # odd length palindrome
            l, r = i, i
            while l >= 0 and r < n and s[l] == s[r]:
                if r-l+1 > ans_len:
                    ans = s[l:r+1]
                    ans_len = r-l+1
                l -= 1
                r += 1
            # even length palindrome
            l, r = i, i+1
            while l >= 0 and r < n and s[l] == s[r]:
                if r-l+1 > ans_len:
                    ans = s[l:r+1]
                    ans_len = r-l+1
                l -= 1
                r += 1
        return ans