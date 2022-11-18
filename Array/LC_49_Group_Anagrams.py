# Written by: Jian-Yuan Lin
# Date: 2022.11.17

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mapping = collections.defaultdict(list)
        for item in strs:
            sorted_string = "".join(sorted(item))
            mapping[sorted_string].append(item)
        
        ans = []
        for item in mapping:
            ans.append(mapping[item])
        return ans