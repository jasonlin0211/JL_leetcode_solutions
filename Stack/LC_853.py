# Written by: Jian-Yuan Lin
# Date: 2022.12.05

class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = [(position[i], speed[i]) for i in range(len(position))]
        cars.sort()
        # monotonic increasing stack to store the required time
        stack = []
        
        for i in range(len(cars)-1, -1, -1):
            t_needed = (target - cars[i][0]) / cars[i][1]
            while stack and t_needed <= stack[-1]:
                # make the faster car arrived the same as the slower car as a fleet
                prev_t = stack.pop()
                t_needed = prev_t
            stack.append(t_needed)
        return len(stack)