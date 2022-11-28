# Written by: Jian-Yuan Lin
# Date: 2022.11.28

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q = collections.deque()
        ans = []
        for i in range(len(nums)):
            while q and q[-1] < nums[i]:
                q.pop()
            q.append(nums[i])
            if i >= k -1:
                ans.append(q[0])
                if q[0] == nums[i-k+1]:
                    q.popleft()
        return ans