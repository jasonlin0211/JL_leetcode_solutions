# Written by: Jian-Yuan Lin
# Date: 2022.11.17

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l, r = 0, len(numbers) - 1
        while l < r:
            temp = numbers[l] + numbers[r]
            if temp == target:
                return [l + 1, r+1]
            if temp > target:
                r -= 1
            else:
                l += 1
        """
        Hashmap version
        mapping = collections.defaultdict(int)
        for idx, num in enumerate(numbers):
            if target - num in mapping:
                return sorted([idx+1, mapping[target-num] + 1])
            mapping[num] = idx
        
        """