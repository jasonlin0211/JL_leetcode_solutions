# Written by: Jian-Yuan Lin
# Date: 2022.11.17

class Solution:
    def trap(self, height: List[int]) -> int:
        # use O(1) space complexity
        n = len(height)
        l, r = 0, n-1
        leftmax, rightmax = height[l], height[r]
        ans = 0
        while l < r:
            # shift the smaller side and consider the contribution
            # don't need the bigger side's number since we need min(L,R) - height
            # bigger one doesn't matter, that's why we shift the pointer in the
            # smaller side
            if leftmax < rightmax:
                l += 1
                leftmax = max(height[l], leftmax)
                ans += leftmax - height[l]
            else:
                r -= 1
                rightmax = max(height[r], rightmax)
                ans += rightmax - height[r]
                
        return ans
        
        """
        Time O(n) Space O(n)
        
        n = len(height)
        left_max, right_max = [0] * n, [0] * n
        left_max[0] = height[0]
        right_max[n-1] = height[n-1]
        
        for i in range(1, n):
            left_max[i] = max(left_max[i-1], height[i])
        
        for i in range(n-2, -1, -1):
            right_max[i] = max(right_max[i+1], height[i])
        
        ans = 0
        for i in range(n):
            ans += (min(left_max[i], right_max[i]) - height[i])
        return ans
        
        """