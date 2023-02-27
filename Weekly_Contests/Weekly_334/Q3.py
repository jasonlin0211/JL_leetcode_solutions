class Solution:
    def maxNumOfMarkedIndices(self, nums: List[int]) -> int:
        # even better thought: we can use two pointers to find out the first k numbers we can pairs
        l = 0
        n = len(nums)
        nums.sort()
        for r in range((n+1)//2, n):
            if nums[l] * 2 <= nums[r]:
                l += 1
        return 2 * l

        '''
        # change the thought!
        # if you can match k pairs, then you can definitely match k-1, k-2...
        # if you can't match k pairs, then you can definitely not match k+1, k+2...
        # so we can binary search the possible pairs k!
        # to get if we can match k pairs, sort the nums and choos the first k and last k numbers and match

        nums.sort()
        l, r = 0, len(nums)//2 + 1

        def can_pair(nums, k):
            ans = True
            for i in range(k):
                if nums[i] * 2 > nums[len(nums)-k+i]:
                    ans = False
                    break
            return ans

        while l < r:
            mid = l + (r - l) // 2
            if can_pair(nums, mid):
                l = mid + 1
            else:
                r = mid
        return 2 * (l-1)
        '''