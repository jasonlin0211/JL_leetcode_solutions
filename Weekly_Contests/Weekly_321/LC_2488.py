# Written by: Jian-Yuan Lin
# Date: 2022.11.28

class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        pos = nums.index(k)
        count = collections.defaultdict(int)
        count[0] = 1 # k itself
        c = 0
        for i in range(pos+1, len(nums)):
            c += 1 if nums[i] > k else -1
            count[c] += 1
        c = 0 
        ans = count[0] + count[1] # odd, even
        for i in range(pos-1, -1, -1):
            c += 1 if nums[i] < k else -1
            ans += count[c] + count[c+1] # we can directly count answer since we have the count for right hand side!
        return ans