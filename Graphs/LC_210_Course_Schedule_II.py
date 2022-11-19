# Written by: Jian-Yuan Lin
# Date: 2022.11.18

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # practice topology sorting
        n = numCourses
        indegree = [0] * n
        mapping = collections.defaultdict(list)
        total_edges, removed_edges = 0, 0
        for start, end  in prerequisites:
            indegree[end] += 1
            mapping[start].append(end)
            total_edges += 1
        
        q = collections.deque()
        for i in range(n):
            if indegree[i] == 0:
                q.append(i)
        ans = []
        while q:
            size = len(q)
            for _ in range(size):
                cur = q.popleft()
                ans.append(cur)
                for nxt in mapping[cur]:
                    indegree[nxt] -= 1
                    removed_edges += 1
                    if indegree[nxt] == 0:
                        q.append(nxt)
        return ans[::-1] if removed_edges == total_edges else []