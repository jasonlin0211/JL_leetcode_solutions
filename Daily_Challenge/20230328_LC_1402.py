class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        # this is too smart....
        res = total = 0
        A.sort()
        while A and A[-1] + total > 0:
            total += A.pop()
            res += total
        return res
        '''
        satisfaction.sort()
        n = len(satisfaction)
        mem = {}

        def dp(i, t):
            if i >= n:
                return 0
            if (i, t) in mem:
                return mem[(i, t)]
            mem[(i, t)] = 0
            # choose to cook
            mem[(i, t)] = max(mem[(i, t)], t * satisfaction[i] + dp(i+1, t+1))
            # choose to not cook
            mem[(i, t)] = max(mem[(i, t)], dp(i+1, t))
            return mem[(i, t)]
        
        return dp(0, 1)
        '''