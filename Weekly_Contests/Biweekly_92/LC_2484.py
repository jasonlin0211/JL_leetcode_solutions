# Written by: Jian-Yuan Lin
# Date: 2022.11.28

class Solution:
    def countPalindromes(self, s: str) -> int:
        suf = [0] * 10 # current suffix count for 0 - 9
        suf2 = [0] * 100 # current suffix count for 2 digits 00 - 99
        n = len(s)
        for i in range(n-1, -1, -1):
            d = int(s[i])
            for j, c in enumerate(suf):
                suf2[d* 10 + j] += c
            suf[d] += 1
        ans = 0
        pre = [0] * 10 # current prefix count for 0 - 9
        pre2 = [0] * 100 # current prefix count for 2 digits 00 - 99
        for i in range(n):
            # delete i @ suffix first as i can't be used
            d = int(s[i])
            suf[d] -= 1
            for j, c in enumerate(suf):
                suf2[d* 10 + j] -= c
            # sum the 2 digits in the left and right side
            ans += sum(c1 * c2 for c1, c2 in zip(pre2, suf2))
            # update the prefix now
            for j, c in enumerate(pre):
                pre2[d* 10 + j] += c
            pre[d] += 1
        return ans % (10**9 + 7)