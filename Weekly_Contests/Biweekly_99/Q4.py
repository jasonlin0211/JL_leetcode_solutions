class Solution:
    def rootCount(self, edges: List[List[int]], guesses: List[List[int]], k: int) -> int:
        # literally try every possible node as root
        # count the correct guess by using dfs and memoization since it's tree
        # from a given node 1 to node 2, there's only one path
        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        seen = set()
        for u, v in guesses:
            seen.add((u, v))
        
        mem = {}

        def correct_guess(i, prev):
            if (i, prev) in mem:
                return mem[(i, prev)]
            mem[(i, prev)] = 0
            for nxt in graph[i]:
                if nxt == prev:
                    continue
                if (i, nxt) in seen:
                    mem[(i, prev)] += 1
                mem[(i, prev)] += correct_guess(nxt, i)
            return mem[(i, prev)]

        ans = 0
        for i in range(len(edges) + 1):
            if correct_guess(i, -1) >= k:
                ans += 1
        return ans