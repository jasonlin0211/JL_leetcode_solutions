# Written by: Jian-Yuan Lin
# Date: 2023.01.07

class Solution:
    def isItPossible(self, word1: str, word2: str) -> bool:
        if word1 == word2:
            return True
        count1, count2 = [0] * 26, [0] * 26
        set1, set2 = set(), set()
        for ch in word1:
            count1[ord(ch) - ord('a')] += 1
            set1.add(ch)
            
        
        for ch in word2:
            count2[ord(ch) - ord('a')] += 1
            set2.add(ch)
        distinct_1, distinct_2 = len(set1), len(set2)
        
        
        for item1 in range(26):
            for item2 in range(26):
                if count1[item1] == 0 or count2[item2] == 0 or item1 == item2:
                    continue
                    
                temp1, temp2 = distinct_1, distinct_2
                original_count1, original_count2 = count1[item1], count1[item2]
                original_count3, original_count4 = count2[item1], count2[item2]
            
                count1[item1] -= 1
                if original_count1 == 1 and count1[item1] == 0:
                    temp1 -= 1
                count1[item2] += 1
                if original_count2 == 0 and count1[item2] == 1:
                    temp1 += 1
                
                count2[item1] += 1
                if original_count3 == 0 and count2[item1] == 1:
                    temp2 += 1
                count2[item2] -= 1
                if original_count4 == 1 and count2[item2] == 0:
                    temp2 -= 1
                
                if temp1 == temp2:
                    return True
                count1[item1], count1[item2] = original_count1, original_count2
                count2[item1], count2[item2] = original_count3, original_count4
                
                
        return False