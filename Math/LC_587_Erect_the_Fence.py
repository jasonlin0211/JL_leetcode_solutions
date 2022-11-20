# Written by: Jian-Yuan Lin
# Date: 2022.11.18

class Solution:
    def outerTrees(self, trees: List[List[int]]) -> List[List[int]]:
        trees = sorted(trees, key=lambda p: (p[0], p[1]))
        #print(trees)
        #edge case
        if len(trees) <= 1:
            return trees
        def orientation(O, A, B):
            return (A[0] - O[0]) * (B[1] - O[1]) - (A[1] - O[1]) * (B[0] - O[0])
        
        # Build lower hull
        lower = []
        for p in trees:
            while len(lower) >= 2 and orientation(lower[-2], lower[-1], p) < 0:
                lower.pop()
            lower.append(p)

        # Build upper hull
        upper = []
        for p in reversed(trees):
            while len(upper) >= 2 and orientation(upper[-2], upper[-1], p) < 0:
                upper.pop()
            upper.append(p)
        
        ans_list = lower[:-1] + upper[:-1]
        seen = set()
        ans = []
        for a in ans_list:
            a_tuple = (a[0], a[1])
            if a_tuple in seen:
                continue
            seen.add(a_tuple)
            ans.append(a)
        
        return ans