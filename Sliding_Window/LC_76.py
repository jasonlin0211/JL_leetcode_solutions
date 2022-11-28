# Written by: Jian-Yuan Lin
# Date: 2022.11.28

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        count_s, count_t  = collections.defaultdict(int), collections.defaultdict(int)
        for ch in t:
            count_t[ch] += 1
        need = len(count_t)
        start, end, ans_len = -1, -1, float('inf')
        have = 0
        l, r = 0, 0
        for r in range(len(s)):
            count_s[s[r]] += 1
            if s[r] in count_t and count_s[s[r]] == count_t[s[r]]:
                have += 1
            # shrink the left side if have == need
            while have == need:
                # update the answer first
                lens = r - l + 1
                if lens < ans_len:
                    ans_len = lens
                    start, end = l, r
                # move left pointers
                count_s[s[l]] -= 1
                if s[l] in count_t and count_s[s[l]] < count_t[s[l]]:
                    have -= 1
                l += 1
        #print(start, end, ans_len)
        return s[start:end+1] if ans_len != float('inf') else ""