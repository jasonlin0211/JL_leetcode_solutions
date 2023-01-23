# Written by: Jian-Yuan Lin
# Date: 2023.01.21

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        ans = []
        
        def is_palid(s):
            return s == s[::-1]
        def dfs(s, curr, ans):
            #print(s)
            if len(s) == 0:
                ans.append(curr[:])
                return 
            for i in range(len(s)):
                first, second = s[:i+1], s[i+1:] # guarantee we have at least one char in first
                if is_palid(first):
                    curr.append(first)
                    dfs(second, curr, ans)
                    curr.pop()
        dfs(s, [], ans)
        return ans