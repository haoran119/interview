#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul  1 19:54:40 2019

@author: Hao
"""


class Solution:
    # check bit in loop
    # note that we should not shift right on n directly,
    # otherwise it will run into infinite loop when n is negative
    def hammingWeight1(self, n: int) -> int:
        # n is a bit string of length 32
        result = sum(1 for i in range(32) if n & (1 << i))

        return result

    # bit manipulation
    # n & (n - 1) will change the right most 1 of n in bit to 0
    def hammingWeight(self, n: int) -> int:
        result = 0

        while (n):
            n &= (n - 1)
            result += 1

        return result


mySolution = Solution()
input = 0x00000000000000000000000000001011
result = mySolution.hammingWeight(input)
print(result)
