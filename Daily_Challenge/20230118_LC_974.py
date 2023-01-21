# Written by: Jian-Yuan Lin
# Date: 2023.01.18
# very similar to LC 560, so I did it again

class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        freq = [0] * k
        freq[0] = 1
        total = 0
        ans = 0
        for num in nums:
            total += num
            rem = total % k
            if rem < 0:
                rem += k
            ans += freq[rem] # if the x % k = rem, that means x = (bk) + k 
            freq[rem] += 1
        return ans