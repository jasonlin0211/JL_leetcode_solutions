# Written by: Jian-Yuan Lin
# Date: 2023.01.07

class Solution:
    def categorizeBox(self, length: int, width: int, height: int, mass: int) -> str:
        volume = length * width * height

        def check_bulky(l, w, h, v):
            return l >= 10**4 or w >= 10**4 or h >= 10**4 or v >= 10**9
        def check_heavy(m):
            return m >= 100

        is_bulky = check_bulky(length, width, height, volume)
        is_heavy = check_heavy(mass)

        if is_bulky and is_heavy:
            return "Both"
        elif not is_bulky and not is_heavy:
            return "Neither"
        elif is_bulky and not is_heavy:
            return "Bulky"
        else:
            return "Heavy"