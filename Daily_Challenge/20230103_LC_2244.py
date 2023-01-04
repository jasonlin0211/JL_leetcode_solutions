# Written by: Jian-Yuan Lin
# Date: 2023.01.03

class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        count = collections.defaultdict(int)
        for t in tasks:
            count[t] += 1
        ans = 0
        for item in count:
            if count[item] == 1:
                return -1
            if count[item] % 3 == 0:
                ans += count[item] // 3
            # If count % 3 = 1; (count / 3 - 1) groups of triplets and 2 pairs.
            # If count % 3 = 2; (count / 3) groups of triplets and 1 pair.
            else:
                ans += count[item] // 3 + 1
        return ans

        '''
        # using top down DP + memoization to solve the rounds needed, this is too complicated
        mem = {}
        mem[3] = 1
        mem[2] = 1

        def solve(f):
            if f in mem:
                return mem[f]
            if f == 1:
                return float('inf')
            mem[f] = min(1 + solve(f-3), 1 + solve(f-2))
            return mem[f]
        
        for item in count:
            if count[item] == 1:
                return -1
            ans += solve(count[item])
        return ans
        '''
       