# Written by: Jian-Yuan Lin
# Date: 2022.11.27

class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        ans = [[] for _ in range(2)]
        count = collections.defaultdict(list)
        seen = set()
        max_value = 0
        for winner, loser in matches:
            count[loser].append(winner)
            seen.add(winner)
            seen.add(loser)
            max_value = max(max_value, winner, loser)
        
        for item in range(1, max_value+1):
            if item not in seen:
                continue
            if item not in count:
                ans[0].append(item)
            elif len(count[item]) == 1:
                ans[1].append(item)
        return ans