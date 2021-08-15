from typing import List


class Solution:
    def quick_sort(self, nums: List[int], left: int, right: int):
        # ending condition
        if left >= right:
            return

        # partition with nums[left] as the base number
        i, j = left, right
        while i < j:
            while i < j and nums[j] >= nums[left]:
                j -= 1
            while i < j and nums[i] <= nums[left]:
                i += 1
            nums[i], nums[j] = nums[j], nums[i]
        # place base number on the right position
        nums[left], nums[i] = nums[i], nums[left]

        # divide and conquer
        self.quick_sort(nums, left, i - 1)
        self.quick_sort(nums, i + 1, right)


if __name__ == '__main__':
    mySolution = Solution()
    list_num = [i for i in range(10, 0, -1)]

    print('list_num before quick sort : {}'.format(str(list_num)))

    mySolution.quick_sort(list_num, 0, len(list_num) - 1)

    print('list_num after quick sort : {}'.format(str(list_num)))
