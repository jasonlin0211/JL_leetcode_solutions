# Written by: Jian-Yuan Lin
# Date: 2022.11.28

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        count = collections.defaultdict(int)
        for num in arr:
            count[num] += 1
        seen = set()
        for freq in count.values():
            if freq in seen:
                return False
            seen.add(freq)
        return True