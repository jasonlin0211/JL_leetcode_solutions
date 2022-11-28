# Written by: Jian-Yuan Lin
# Date: 2022.11.22

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m, n = len(nums1), len(nums2)
        if m > n:
            return self.findMedianSortedArrays(nums2, nums1)
        if m == 0:
            if n % 2:
                return nums2[n//2]
            else:
                return (nums2[n//2 - 1] + nums2[n//2]) / 2
        
        k = (m + n + 1) // 2;
        l, r = 0, m
        '''
        the idea is to binary search on the smaller nums, get m1 numbers (A[0] ~ A[m1-1]) and get m2 numbers (B[0] ~ B[m2-1])
        m1 + m2 = k = (m + n + 1)/ 2
        compare condition: A[m1] < B[m2-1] -> move right since A[m1] is not big enough to cover B[m2-1]
        once we reach that, the median must came from A_m1-1, A_m1, B_m2-1, B_m2
        we can use C1 = max(A_m1-1, B_m2-1), C2 = min(A_m1, B_m2)
        '''
        while l < r:
            m1 = l + (r-l)//2
            m2 = k - m1
            if nums1[m1] < nums2[m2-1]:
                l = m1 + 1
            else:
                r = m1

        m1, m2 = l, k-l
        # be careful here
        # c1 can be found by C1 = max(A_m1-1, B_m2-1), but it's possible that m1 <= 0 or m2 <= 0 --> didn't use any of them
        c1 = max(nums1[m1-1] if m1 > 0 else -float('inf') , nums2[m2-1] if m2 > 0 else -float('inf'))
        if (m + n) % 2:
            return c1
        # calculate c2 = min(A_m1, B_m2), but same consideration, if m1 >= m means out of bound
        c2 = min(nums1[m1] if m1 < m else float('inf'), nums2[m2] if m2 < n else float('inf'))
        return (c1 + c2) / 2