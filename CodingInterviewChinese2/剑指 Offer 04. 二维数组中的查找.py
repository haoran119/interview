#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul  1 19:54:40 2019

@author: hao
"""


class Solution(object):
    def findNumberIn2DArray(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """

        if matrix is None or (not matrix):
            return False

        # start from right upper corner
        row, column = 0, len(matrix[0]) - 1

        while row < len(matrix) and column >= 0:
            if matrix[row][column] < target:
                row += 1
            elif matrix[row][column] > target:
                column -= 1
            else:
                return True

        return False


mySolution = Solution()
input = [[1,1]]
result = mySolution.findNumberIn2DArray(input, 2)
print(result)
