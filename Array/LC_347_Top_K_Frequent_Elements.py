# Written by: Jian-Yuan Lin
# Date: 2022.11.17

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # bucket sort
        count = collections.defaultdict(int)
        for num in nums:
            count[num] += 1
        max_freq = max(count.values())
        freq = [[] for i in range(max_freq+1)]
        
        ans = []
        for item in count:
            freq[count[item]].append(item)
        
        for f in range(max_freq, 0, -1):
            for item in freq[f]:
                ans.append(item)
                k -= 1
                if k == 0:
                    return ans