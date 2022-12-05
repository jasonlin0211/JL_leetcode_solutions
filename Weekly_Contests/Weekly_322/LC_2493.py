# Written by: Jian-Yuan Lin
# Date: 2022.12.03

class Solution:
    def magnificentSets(self, n: int, edges: List[List[int]]) -> int:
        # this is very difficult!
        # Since |y - x| = 1, it is actually similar to the biparitate problem, if the graph is not biparitate, then it's impossible
        # if it's possible, we need to do BFS to find the maximum depth we can get and add it to the answer
        # to find if the graph is biparitate, we can use DFS, see LC 785 for reference
        graph = collections.defaultdict(list)
        for start, end in edges:
            start -= 1
            end -= 1
            graph[start].append(end)
            graph[end].append(start)
        
        # return the max ID, tricky here, declare the seen vector outside to avoid duplicated declaration every time
        # if we visit the node at same time, then that means we have seen this node before in this search
        time = [0] * n
        clock = 0
        def bfs(i):
            mx = 0
            nonlocal clock
            clock += 1
            time[i] = clock
            q = collections.deque()
            q.append((i, base))
            while q:
                cur, ID = q.popleft()
                mx = max(mx, ID)
                for nxt in graph[cur]:
                    if time[nxt] != clock:
                        time[nxt] = clock
                        q.append((nxt, ID + 1))
            return mx
            
        # check if the graph is biparitate
        color = [0] * n
        def dfs(i, c):
            nodes.append(i)
            color[i] = c
            for nxt in graph[i]:
                if color[nxt] == c or (color[nxt] == 0 and not dfs(nxt, -c)):
                    return False
            return True
        ans = 0
        for i, c in enumerate(color):
            if c:
                continue
            # check if the graph is biparitate
            nodes = []
            if not dfs(i, 1):
                return -1
            base = ans + 1
            # update the maximum ID that can possibly get from BFS
            for x in nodes:
                ans = max(ans, bfs(x))
        return ans