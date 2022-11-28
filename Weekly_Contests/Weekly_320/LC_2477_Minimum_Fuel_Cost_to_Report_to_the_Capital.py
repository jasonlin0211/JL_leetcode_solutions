# Written by: Jian-Yuan Lin
# Date: 2022.11.20

# learned from https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital/solution/kao-lu-mei-tiao-bian-shang-zhi-shao-xu-y-uamv/

class Solution:
    def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
        # convert to calculate ceil(size of subtree/seats)
        # means we want to know the summation of how many cars
        # are on each edge, given 0 as root
        graph = collections.defaultdict(list)
        ans = 0
        for u, v in roads:
            graph[u].append(v)
            graph[v].append(u)
        # calculate the subtree size
        def dfs(root, prev):
            size = 1
            for nxt in graph[root]:
                if nxt != prev:
                    size += dfs(nxt, root)
            if root:
                nonlocal ans
                # think about seats = 5, size = 2 -> we need 1
                #             seats = 5, size = 5 -> we still need 1
                ans += (size + seats - 1) // seats
            return size
        dfs(0, -1)
        return ans