#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul  1 19:54:40 2019

@author: hao
"""


class Solution(object):
    def findRepeatNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        if nums is None:
            return -1

        set_num = set()

        for num in nums:
            if num in set_num:
                return num
            set_num.add(num)

        return -1

    def findRepeatNumber1(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        if nums is None:
            return -1

        for i in range(len(nums)):
            while (i != nums[i]):
                if (nums[i] == nums[nums[i]]):
                    return nums[i]

                # Need to swap nums[nums[i]] first, otherwise nums[i] varies
                # which will cause wrong nums[nums[i]]
                nums[nums[i]], nums[i] = nums[i], nums[nums[i]]

        return -1


mySolution = Solution()

result = mySolution.findRepeatNumber([2, 3, 1, 0, 2, 5, 3])

print(result)
