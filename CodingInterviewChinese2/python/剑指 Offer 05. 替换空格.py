#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul  1 19:54:40 2019

@author: Hao
"""


class Solution:
    # In Python, string is immutable
    # not available for in-place replacement
    def replaceSpace(self, s: str) -> str:
        result = []

        for c in s:
            if c == ' ':
                result.append('%20')
            else:
                result.append(c)

        return ''.join(result)


mySolution = Solution()
input = "We are happy."
result = mySolution.replaceSpace(input)
print(result)
