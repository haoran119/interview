#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul  1 19:54:40 2019

@author: Hao
"""


class Solution:
    # divide and conquer
    # x^n = {(x^2)^(n//2) if n is even; (x^2)^(n//2) * x if n is odd}
    def myPow(self, x: float, n: int) -> float:
        if x == 0:
            return 0
        if n == 0:
            return 1
        if n == 1:
            return x

        result = 1

        if n < 0:
            x, n = 1 / x, -n

        while n:
            # n % 2
            if n & 1 == 1:
                result *= x

            x *= x
            # n // 2
            n >>= 1

        return result


mySolution = Solution()
input = 2.00000
result = mySolution.myPow(input, 10)
print(result)
