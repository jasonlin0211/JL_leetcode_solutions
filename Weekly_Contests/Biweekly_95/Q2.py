# Written by: Jian-Yuan Lin
# Date: 2023.01.07

class DataStream:

    def __init__(self, value: int, k: int):
        self.queue = collections.deque()
        self.seen_queue = collections.defaultdict(int)
        self.value = value
        self.k = k
    
    def consec(self, num: int) -> bool:
        self.queue.append(num)
        self.seen_queue[num] += 1
        if len(self.queue) < self.k:
            return False
        if len(self.queue) > self.k:
            to_pop = self.queue.popleft()
            self.seen_queue[to_pop] -= 1
        return self.seen_queue[self.value] == self.k