# Written by: Jian-Yuan Lin
# Date: 2022.12.06

class Solution:
    def numDecodings(self, s: str) -> int:
        mem = {}
        n = len(s)
        mem[n] = 1

        def dp(i):
            if i in mem:
                return mem[i]
            if s[i] == "0":
                return 0
            # include one digit
            ans = dp(i+1)
            # if two digits are valid, include them
            if i+1 < n and int(s[i:i+2]) <= 26:
                ans += dp(i+2)
            mem[i] = ans
            return mem[i]
        return dp(0)