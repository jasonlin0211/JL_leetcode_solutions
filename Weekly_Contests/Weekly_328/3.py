# Written by: Jian-Yuan Lin
# Date: 2023.01.22

class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        ans = 0
        l = 0
        count = collections.defaultdict(int)
        good_pairs = 0
        for x in nums:
            # update the pairs first, since previously have count[x] pair, if new x is counted, we have count[x] more pairs
            good_pairs += count[x]
            count[x] += 1
            ans += l
            # squeeze the window by moving the left pointer one by one, and if still have enough good pairs, we add one to ans
            while good_pairs >= k:
                ans += 1
                # update the count first, since we eliminate 1 nums[l], means that we reduced count[nums[l]] pairs, be careful!
                count[nums[l]] -= 1
                good_pairs -= count[nums[l]] 
                l += 1
        return ans