# Written by: Jian-Yuan Lin
# Date: 2023.01.22

class Solution:
    def confusingNumberII(self, n: int) -> int:
        # this recursive method is more efficient!!!!
        rotate180 = [[0, 0], [1, 1], [6, 9], [8, 8], [9, 6]]
        self.res = 0

        def dfs(num, numRotated, unit):
            if num != numRotated:
                self.res += 1

            for d, dRotated in rotate180:
                if d == 0 and num == 0: continue  # Skip zero infinity!
                if num * 10 + d > n: break  # Over N already!
                dfs(num * 10 + d, dRotated * unit + numRotated, unit * 10)

        dfs(0, 0, 1)
        return self.res
        '''
        TLE...
        mappings = {'0' : '0', '1' : '1', '6' : '9', '8' : '8', '9' : '6'}
        self.count = 0

        def is_confusing(s):
            temp = ""
            for ch in s:
                if ch not in mappings:
                    return False
                temp += mappings[ch]
            #print(s, temp[::-1])
            return s != temp[::-1]
            
        def get_combos(s):
            #print(s)
            if int(s) > n:
                return
            
            if is_confusing(s):
                #print(s)
                self.count += 1
            x = int(s)
            x *= 10
            for key in mappings:
                temps = str(x + int(key))
                get_combos(temps)
            return
                

        get_combos('1')
        get_combos('6')
        get_combos('8')
        get_combos('9')

        return self.count
        '''