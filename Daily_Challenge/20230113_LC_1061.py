# Written by: Jian-Yuan Lin
# Date: 2023.01.13

class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        root = [i for i in range(26)]

        def find(x):
            if x != root[x]:
                root[x] = find(root[x])
            return root[x]
        
        def union(x, y):
            rx, ry = find(x), find(y)
            if rx != ry:
                if rx < ry:
                    root[ry] = rx
                else:
                    root[rx] = ry
        
        for i in range(len(s1)):
            c1, c2 = s1[i], s2[i]
            if c1 != c2:
                union(ord(c1) - ord('a'), ord(c2) - ord('a'))
        
        chars = "abcdefghijklmnopqrstuvwxyz"
        ans = ""
        for c in baseStr:
            ans += chars[find(ord(c) - ord('a'))]
        return ans