# Written by: Jian-Yuan Lin
# Date: 2022.11.22

class TimeMap:

    def __init__(self):
        self.map = collections.defaultdict(list)
    def set(self, key: str, value: str, timestamp: int) -> None:
        self.map[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        content = self.map[key]
        #print(content)
        l, r = 0, len(content)
        while l < r:
            mid = l + (r-l)//2
            if content[mid][0] > timestamp:
                r = mid
            else:
                l = mid + 1
        if l-1 < 0:
            return ""
        return content[l-1][1]