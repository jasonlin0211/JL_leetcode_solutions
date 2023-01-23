# Written by: Jian-Yuan Lin
# Date: 2023.01.22

class Solution:
    def differenceOfSum(self, nums: List[int]) -> int:
        ele_sum = sum(nums)
        digit_sum = 0
        
        def cal_digit_sum(num):
            ans = 0
            while num:
                ans += (num % 10)
                num //= 10
            return ans
        for num in nums:
            digit_sum += cal_digit_sum(num)
        return abs(ele_sum - digit_sum)