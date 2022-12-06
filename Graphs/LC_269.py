# Written by: Jian-Yuan Lin
# Date: 2022.12.05

class Solution:
    def alienOrder(self, words: List[str]) -> str:
        mapping = collections.defaultdict(list)
        indegree = collections.defaultdict(int)
        for word in words:
            for c in word:
                indegree[c] = 0
        total_edges = 0
        for i in range(len(words) - 1):
            first, second = words[i], words[i+1]
            for idx in range(min(len(first), len(second))):
                if first[idx] != second[idx]:
                    mapping[first[idx]].append(second[idx])
                    total_edges += 1
                    indegree[second[idx]] += 1
                    break
            if len(first) > len(second) and second == first[:len(second)]:
                return ""
        q = collections.deque()
        for item in indegree:
            if indegree[item] == 0:
                q.append(item)
        removed_edges = 0
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
        
        return "".join(ans) if removed_edges == total_edges else ""