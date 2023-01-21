# Written by: Jian-Yuan Lin
# Date: 2023.01.18

class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        ans = []
        # standard backtracking problem
        def dfs(s, i, curr, ans):
            if i >= len(s):
                if len(curr) == 4:
                    ans.append(curr[:])
                return
            if len(curr) == 4:
                return
            for d in range(1, 4):
                first = s[i:i+d]
                #print(first)
                if len(first) > 1 and first[0] == "0":
                    continue
                if int(first) > 255:
                    continue
                curr.append(first)
                dfs(s, i+d, curr, ans)
                curr.pop()
        dfs(s, 0, [], ans)
        seen = set()
        for item in ans:
            seen.add(".".join(item))
        return list(seen)
                