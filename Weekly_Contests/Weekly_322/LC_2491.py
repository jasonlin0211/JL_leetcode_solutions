# Written by: Jian-Yuan Lin
# Date: 2022.12.03

class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        n = len(skill)
        groups = n // 2
        total = sum(skill)
        if total % groups != 0:
            return -1
        
        target = total // groups
        ans = 0
        
        count = collections.defaultdict(int)
        for num in skill:
            count[num] += 1
        
        for num in skill:
            if count[num] == 0:
                continue
            if target - num not in count or count[target - num] == 0:
                return -1
            count[num] -= 1
            count[target - num] -= 1
            ans += num * (target - num)
        return ans