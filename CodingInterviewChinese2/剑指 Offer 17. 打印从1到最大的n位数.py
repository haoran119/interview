#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul  1 19:54:40 2019

@author: Hao
"""


from typing import List


class Solution:
    # print the full permutation recursively
    # note that need to remove starting 0s
    def printNumbers(self, n: int) -> List[int]:
        def dfs(index, str_number):
            if index == n:
                # remove the starting 0
                while str_number.startswith('0'):
                    str_number = str_number[1:]
                if str_number:
                    result.append(int(str_number))
                return

            for i in range(10):
                dfs(index + 1, str_number + str(i))

        result = []
        dfs(0, '')

        return result


mySolution = Solution()
input = 3
result = mySolution.printNumbers(input)
print(result)
