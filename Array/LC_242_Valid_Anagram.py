# Written by: Jian-Yuan Lin
# Date: 2022.11.17

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        freq_s, freq_t = [0] * 26, [0] * 26
        
        if len(s) != len(t):
            return False
        n = len(s)
        
        for i in range(n):
            freq_s[ord(s[i]) - ord("a")] += 1
            freq_t[ord(t[i]) - ord("a")] += 1
        
        for i in range(26):
            if freq_s[i] != freq_t[i]:
                return False
        return True