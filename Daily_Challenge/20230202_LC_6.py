# Date: 2023.02.02
# Written by Jian-Yuan Lin

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s
        word = [""] * numRows
        step, idx, i = 1, 0, 0
        while i < len(s):
            word[idx] += s[i]
            idx += step
            if idx == 0:
                step = 1
            elif idx == numRows - 1:
                step = -1
            i += 1
        ans = ""
        for s in word:
            ans += s
        return ans