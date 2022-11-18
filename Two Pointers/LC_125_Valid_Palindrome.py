# Written by: Jian-Yuan Lin
# Date: 2022.11.17

class Solution:
    def isPalindrome(self, s: str) -> bool:
        # Try two pointers
        l, r = 0, len(s) - 1
        
        while l < r:
            while l < r and not s[l].isalnum():
                l += 1
            while l < r and not s[r].isalnum():
                r -= 1
            if s[l].lower() != s[r].lower():
                return False
            l += 1
            r -= 1
        return True
        
        
        """
        def is_pal(s):
            return s == s[::-1]
        to_check = []
        for ch in s:
            if ch.isalnum():
                to_check.append(ch.lower())
        return is_pal(to_check)
        
        """