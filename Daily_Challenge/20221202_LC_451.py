# Written by: Jian-Yuan Lin
# Date: 2022.12.02


class Solution:
    def frequencySort(self, s: str) -> str:
        count = collections.defaultdict(int)
        for ch in s:
            count[ch] += 1
        
        count_list = []
        for ch in count:
            freq = count[ch]
            count_list.append((freq, ch))
        count_list.sort(key = lambda x: -x[0])
        ans = ""
        for freq, ch in count_list:
            ans += ch * freq
        return ans