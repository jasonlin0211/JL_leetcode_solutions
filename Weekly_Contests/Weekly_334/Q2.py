class Solution:
    def divisibilityArray(self, word: str, m: int) -> List[int]:
        ans = []
        x = 0
        for ch in word:
            x = (x * 10 + int(ch)) % m
            ans.append(int(x == 0))
        return ans