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

    # This method fails for [0, 1, 2, 0, 4, 5, 6, 7, 8, 9].
    # Expected result 0, but actual result -1.
    def findRepeatNumber2(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        if nums is None:
            return -1

        start = 0
        end = len(nums) - 1

        def countRange(nums, length, start, end):
            if nums is None:
                return 0

            count = 0
            for i in range(length):
                if (nums[i] >= start and nums[i] <= end):
                    count += 1

            return count

        while end >= start:
            # Need () for operator >>
            middle = (int)(((end - start) >> 1) + start)

            count = countRange(nums, len(nums), start, middle)

            if end == start:
                if count > 1:
                    return start
                else:
                    break

            if count > middle - start + 1:
                end = middle
            else:
                start = middle + 1

        return -1


mySolution = Solution()
result = mySolution.findRepeatNumber([0, 1, 2, 0, 4, 5, 6, 7, 8, 9])
print(result)
