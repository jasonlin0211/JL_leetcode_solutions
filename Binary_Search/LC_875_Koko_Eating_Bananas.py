# Written by: Jian-Yuan Lin
# Date: 2022.11.20

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles) + 1
        
        def cal_time(piles, speed):
            ans = 0
            for p in piles:
                ans += (p + speed - 1) // speed
            return ans
        
        while l < r:
            mid = l + (r-l) // 2
            time = cal_time(piles, mid)
            if time > h:
                l = mid + 1
            else:
                r = mid
        return l