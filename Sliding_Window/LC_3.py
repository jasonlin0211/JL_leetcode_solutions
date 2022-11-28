# Written by: Jian-Yuan Lin
# Date: 2022.11.28

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # two pointers(sliding window) + set!
        seen = set()
        l, r = 0, 0
        ans = 0
        while r < len(s):
            if s[r] in seen:
                while s[r] in seen:
                    seen.remove(s[l])
                    l += 1
            seen.add(s[r])
            ans = max(ans, r-l+1)
            r += 1
        return ans