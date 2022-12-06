# Written by: Jian-Yuan Lin
# Date: 2022.12.05

class MedianFinder:

    def __init__(self):
        self.left, self.right = [], [] # left is maxheap, right is minheap
    def addNum(self, num: int) -> None:
        if not self.left or num <= -self.left[0]:
            heapq.heappush(self.left, -num)
        else:
            heapq.heappush(self.right, num)
            
        if len(self.left) - len(self.right) == 2:
            maxval = -heapq.heappop(self.left)
            heapq.heappush(self.right, maxval)
        elif len(self.left) < len(self.right):
            minval = heapq.heappop(self.right)
            heapq.heappush(self.left, -minval)

    def findMedian(self) -> float:
        if len(self.left) > len(self.right):
            return -self.left[0]
        else:
            return (-self.left[0] + self.right[0]) / 2