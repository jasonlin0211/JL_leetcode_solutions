# Written by: Jian-Yuan Lin
# Date: 2022.12.06

class Solution:
    def countSubstrings(self, s: str) -> int:
        ans = 0
        n = len(s)
        for i in range(n):
            # odd length
            l, r = i, i
            while l >= 0 and r < n and s[l] == s[r]:
                ans += 1
                l -= 1
                r += 1
            # even length
            l, r = i, i + 1
            while l >= 0 and r < n and s[l] == s[r]:
                ans += 1
                l -= 1
                r += 1
        return ans 