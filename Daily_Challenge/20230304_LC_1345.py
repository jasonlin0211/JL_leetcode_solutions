class Solution:
    def minJumps(self, arr: List[int]) -> int:
        
        graph = collections.defaultdict(list)
        for idx, val in enumerate(arr):
            graph[val].append(idx)
        
        q = collections.deque()
        q.append(0)
        seen = set()
        seen.add(0)
        
        steps = 0
        
        n = len(arr)
        while q:
            size = len(q)
            for _ in range(size):
                cur_idx = q.popleft()
                if cur_idx == n-1:
                    return steps
                for nxt in [cur_idx-1, cur_idx+1]:
                    if 0 <= nxt < n and nxt not in seen:
                        q.append(nxt)
                        seen.add(nxt)
                for nxt in graph[arr[cur_idx]]:
                    if nxt not in seen:
                        q.append(nxt)
                        seen.add(nxt)
                graph[arr[cur_idx]].clear()
            steps += 1
            
        
        
        
        return -1