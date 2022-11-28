# Written by: Jian-Yuan Lin
# Date: 2022.11.17

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mapping = collections.defaultdict(int)
        for idx in range(len(nums)):
            if target - nums[idx] in mapping:
                return [idx, mapping[target - nums[idx]]]
            mapping[nums[idx]] = idx