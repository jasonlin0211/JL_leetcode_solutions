# Written by: Jian-Yuan Lin
# Date: 2022.12.03

class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        word_split = sentence.split(" ")
        if len(word_split) == 1:
            return sentence[0] == sentence[-1]
        n = len(word_split)
        for i in range(n):
            first = word_split[i]
            second = word_split[i+1] if i != n-1 else word_split[0]
            if first[-1] != second[0]:
                return False
        return True