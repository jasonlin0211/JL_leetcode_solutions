class Solution:
    def anagramMappings(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # if every idx needs to be used, we need to maintain a list of positions for every num
        pos = collections.defaultdict(list)
        for idx, num in enumerate(nums2):
            pos[num].append(idx)
        ans = []
        for num in nums1:
            ans.append(pos[num].pop())
        return ans
        
        # if not every idx needs to be used in the duplicated case
        # ex. [12,28,46,32,50,12]
        # pos2 = {}
        # for idx, num in enumerate(nums2):
        #     pos2[num] = idx
        # ans = []
        # for num in nums1:
        #     ans.append(pos2[num])
        # return ans