# Written by: Jian-Yuan Lin
# Date: 2023.01.17

class Solution:
    def getIndex(self, reader: 'ArrayReader') -> int:
        # we need to keep the left and right side both have the same length
        l, r = 0, reader.length() - 1
        while l < r:
            h = (r - l + 1) // 2  # half, h * 2 <= r - l + 1
            if reader.compareSub(l, l + h - 1, l + h, l + h * 2 - 1) != 1:
                l = l + h
            else:
                r = l + h - 1
        return l