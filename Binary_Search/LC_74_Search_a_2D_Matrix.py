# Written by: Jian-Yuan Lin
# Date: 2022.11.19

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        first_col = [matrix[i][0] for i in range(len(matrix))]
        # return upperbound - 1
        def find_search_row(col, target):
            l, r = 0, len(col)
            while l < r:
                mid = l + (r-l)//2
                if col[mid] > target:
                    r = mid
                else:
                    l = mid + 1
            return l-1
        
        def find_target(nums, target):
            l, r = 0, len(nums)
            while l < r:
                mid = l + (r-l)//2
                if nums[mid] == target:
                    return mid
                elif nums[mid] > target:
                    r = mid
                else:
                    l = mid + 1
            return l
        
        row = find_search_row(first_col, target) # find the to be search row
        #print(row)
        idx = find_target(matrix[row], target)
        if idx == len(matrix[0]) or matrix[row][idx] != target:
            return False
        return True