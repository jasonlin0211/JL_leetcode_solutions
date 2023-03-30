class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        mem = {}

        def scramble(s1, s2):
            if s1 == s2:
                return True
            if s1 == s2[::-1]:
                return True
            if (s1, s2) in mem:
                return mem[(s1, s2)]
            if Counter(s1) != Counter(s2):
                mem[(s1, s2)] = False
                return False
            mem[(s1, s2)] = False
            l = len(s1)
            for k in range(1, l):
                if scramble(s1[0:k], s2[0:k]) and scramble(s1[k:], s2[k:]):
                    mem[(s1, s2)] = True
                # first and second swap
                if scramble(s1[0:k], s2[l-k:]) and scramble(s1[k:], s2[0:l-k]):
                    mem[(s1, s2)] = True
            return mem[(s1, s2)]
        return scramble(s1, s2)