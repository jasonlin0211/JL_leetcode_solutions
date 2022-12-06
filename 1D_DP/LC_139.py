# Written by: Jian-Yuan Lin
# Date: 2022.12.06

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        # try bottom up
        n = len(s)
        dp = [False] * (n+1)
        dp[n] = True
        
        for i in range(n-1, -1, -1):
            # compare every possible word in wordDict
            for w in wordDict:
                if i + len(w) <= n and s[i:i+len(w)] == w:
                    dp[i] = dp[i+len(w)]
                if dp[i]:
                    break
        return dp[0]
        """
        Top down + memoization
        mem = {}
        mem[""] = True
        worddict = set(wordDict)
        def dp(s):
            if s in mem:
                return mem[s]
            if s in worddict:
                mem[s] = True
                return mem[s]
            # make split
            mem[s] = False
            for i in range(1, len(s)):
                first, second = s[:i], s[i:]
                if dp(first) and second in worddict:
                    mem[s] = True
                    break
            return mem[s]
        return dp(s)
        """
        