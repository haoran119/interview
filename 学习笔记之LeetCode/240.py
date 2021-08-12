class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix or len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        
        row, column = 0, len(matrix[0]) - 1
        
        while row < len(matrix) and column >= 0:
            if target == matrix[row][column]:
                return True
            elif target < matrix[row][column]:
                column -= 1
            else:
                row += 1
        
        return False
    
    def searchMatrix2(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        return any(target in row for row in matrix)
    
    def searchMatrix3(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix or len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        
        def helper(nums, target):
            left, right = 0, len(nums) - 1
            
            while left <= right:
                # remember to use // 2
                middle = (left + right) // 2

                if target == nums[middle]:
                    return True
                elif target < nums[middle]:
                    right = middle - 1
                else:
                    left = middle + 1
            
            return False
        
        for row in matrix:
            if helper(row, target):
                return True
        
        return False
