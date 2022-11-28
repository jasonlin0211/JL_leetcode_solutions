# Written by: Jian-Yuan Lin
# Date: 2022.11.28

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        
        s1_count, s2_count = [0] * 26, [0] * 26
        for ch in s1:
            s1_count[ord(ch) - ord('a')] += 1
        
        for i in range(len(s2)):
            s2_count[ord(s2[i]) - ord('a')] += 1
            if i >= len(s1):
                s2_count[ord(s2[i-len(s1)]) - ord('a')] -= 1
            if s1_count == s2_count:
                return True
        return False