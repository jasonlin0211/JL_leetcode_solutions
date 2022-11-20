# Written by: Jian-Yuan Lin
# Date: 2022.11.19

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        mapping = {}
        mapping['2'] = "abc"
        mapping['3'] = "def"
        mapping['4'] = "ghi"
        mapping['5'] = "jkl"
        mapping['6'] = "mno"
        mapping['7'] = "pqrs"
        mapping['8'] = "tuv"
        mapping['9'] = "wxyz"
        
        ans = []

        def dfs(digits, idx, curr, ans):
            if idx == len(digits):
                ans.append(curr[:])
                return
            for d in mapping[digits[idx]]:
                dfs(digits, idx+1, curr + d, ans)

        dfs(digits, 0, "", ans)
        return ans