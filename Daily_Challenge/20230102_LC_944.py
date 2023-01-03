# Written by: Jian-Yuan Lin
# Date: 2023.01.02

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        n = len(strs[0])
        to_delete = [0] * n
        for i in range(len(strs) - 1):
            first, second = strs[i], strs[i+1]
            for j in range(n):
                if to_delete[j] == 1:
                    continue
                if first[j] > second[j]:
                    to_delete[j] = 1
        return sum(to_delete)