#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul  1 19:54:40 2019

@author: Hao
"""


class Solution:
    # Greedy. Split n into 3 as many as possible.
    # In Py3, integers have unlimited precision.
    def cuttingRope(self, n: int) -> int:
        if n <= 3:
            return n - 1

        # need to use 1000000007 instead of 1e9 + 7
        # otherwise will cause wrong result when n = 120
        a, b, p = n // 3, n % 3, 1000000007
        if b == 0:
            return (3 ** a) % p
        elif b == 1:
            return (3 ** (a - 1)) * 4 % p
        else:
            return (3 ** a) * 2 % p


mySolution = Solution()
input = 120
result = mySolution.cuttingRope(input)
print(result)
