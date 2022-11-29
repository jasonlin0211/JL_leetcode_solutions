# Written by: Jian-Yuan Lin
# Date: 2022.11.28

class RandomizedSet:

    def __init__(self):
        self.nums_map = {}
        self.nums_list = []

    def insert(self, val: int) -> bool:
        result = False
        if val not in self.nums_map:
            result = True
        if result:
            self.nums_map[val] = len(self.nums_list)
            self.nums_list.append(val)
        return result

    def remove(self, val: int) -> bool:
        result = True
        if val not in self.nums_map:
            result = False
        if result:
            idx = self.nums_map[val]
            last_val = self.nums_list[-1]
            self.nums_list[idx] = last_val
            self.nums_list.pop()
            self.nums_map[last_val] = idx
            del self.nums_map[val]
        return result
    def getRandom(self) -> int:
        idx = random.randint(0, len(self.nums_list) - 1)
        return self.nums_list[idx]

# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()