from typing import List


class Solution:
    def quick_sort(self, nums: List[int], left: int, right: int):
        # 子数组长度为 1 时终止递归
        if left >= right:
            return

        # 哨兵划分操作（以 nums[left] 作为基准数）
        i, j = left, right
        while i < j:
            while i < j and nums[j] >= nums[left]:
                j -= 1
            while i < j and nums[i] <= nums[left]:
                i += 1
            nums[i], nums[j] = nums[j], nums[i]
        nums[left], nums[i] = nums[i], nums[left]

        # 递归左（右）子数组执行哨兵划分
        self.quick_sort(nums, left, i - 1)
        self.quick_sort(nums, i + 1, right)


if __name__ == '__main__':
    mySolution = Solution()
    list_num = [i for i in range(10, 0, -1)]

    print('list_num before quick sort : {}'.format(str(list_num)))

    mySolution.quick_sort(list_num, 0, len(list_num) - 1)

    print('list_num after quick sort : {}'.format(str(list_num)))
