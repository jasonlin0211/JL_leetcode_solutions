# Written by: Jian-Yuan Lin
# Date: 2022.12.02

class Solution:
    def calculateTime(self, keyboard: str, word: str) -> int:
        pos = {}
        for i, ch in enumerate(keyboard):
            pos[ch] = i
        ans = 0
        prev = 0
        for ch in word:
            ans += abs(pos[ch] - prev)
            prev = pos[ch]
        return ans