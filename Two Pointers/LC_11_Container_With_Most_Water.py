# Written by: Jian-Yuan Lin
# Date: 2022.11.17

class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1
        ans = 0
        while l < r:
            minH = min(height[l], height[r])
            area = minH * (r - l)
            ans = max(ans, area)
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return ans