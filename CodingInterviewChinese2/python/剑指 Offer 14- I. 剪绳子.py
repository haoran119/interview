#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul  1 19:54:40 2019

@author: Hao
"""

import math


class Solution:
    # Greedy. Split n into 3 as many as possible.
    def cuttingRope(self, n: int) -> int:
        # n = 3 = 2 + 1
        # n = 2 = 1 + 1
        if n <= 3:
            return n - 1

        a, b = n // 3, n % 3
        # n = 3^a
        if b == 0:
            return int(math.pow(3, a))
        # n = 3^(a-1) * 4
        elif b == 1:
            return int(math.pow(3, a - 1) * 4)
        # n = 3^a * 2
        else:
            return int(math.pow(3, a) * 2)


mySolution = Solution()
input = 10
result = mySolution.cuttingRope(input)
print(result)
