#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul  1 19:54:40 2019

@author: Hao
"""

from typing import List


class Solution:
    # two points
    # same idea as partition in quick sort
    def exchange(self, nums: List[int]) -> List[int]:
        if not nums:
            return nums

        left, right = 0, len(nums) - 1

        while left < right:
            while left < right and nums[left] & 0x1 != 0:
                left += 1
            while left < right and nums[right] & 0x1 == 0:
                right -= 1
            if left < right:
                nums[left], nums[right] = nums[right], nums[left]

        return nums


mySolution = Solution()
input = [1, 2, 3, 4]
result = mySolution.exchange(input)
print(result)
