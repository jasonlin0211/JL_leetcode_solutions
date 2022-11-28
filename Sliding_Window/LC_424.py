# Written by: Jian-Yuan Lin
# Date: 2022.11.28

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        # two pointers
        l, r = 0, 0
        count = collections.defaultdict(int)
        ans = 0
        max_f = 0
        while r < len(s):
            count[s[r]] += 1
            max_f = max(max_f, count[s[r]])
            if r-l+1 > max_f + k: # current interval length is greater than max freq + k
                # shift left pointer
                count[s[l]] -= 1
                l += 1
            ans = max(ans, r-l+1)
            r += 1
        return ans