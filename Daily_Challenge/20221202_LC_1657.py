# Written by: Jian-Yuan Lin
# Date: 2022.12.02

class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        # two conditions:
        # 1. two strings must have same chars
        # 2. the frequency of all the characters is always the same, for example aab(2:a,1:b), bba(2:b,1:a)
        if len(word1) != len(word2):
            return False
        count1, count2 = collections.defaultdict(int), collections.defaultdict(int)
        for i in range(len(word1)):
            count1[word1[i]] += 1
            count2[word2[i]] += 1
    
        char_word1, char_word2 = [], []
        freq_word1, freq_word2 = [], []
        for item in count1:
            char_word1.append(item)
            freq_word1.append(count1[item])

        for item in count2:
            char_word2.append(item)
            freq_word2.append(count2[item])
        
        char_word1.sort()
        char_word2.sort()
        if char_word1 != char_word2:
            return False
        freq_word1.sort()
        freq_word2.sort()
        return freq_word1 == freq_word2
        