# Written by: Jian-Yuan Lin
# Date: 2023.01.26

class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        seen = set(words)
        mem = {}
        ans = []

        def dp(word):
            if word in mem:
                return mem[word]
            mem[word] = False
            for i in range(1, len(word)):
                first, second = word[:i], word[i:]
                if first in seen and second in seen or (second in seen and dp(first)):
                    mem[word] = True
                    return mem[word]
            return mem[word]

        for word in words:
            if dp(word):
                ans.append(word)
        return ans