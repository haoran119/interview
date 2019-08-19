class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        def three_way_partition(nums, middle):
            i, j, n = 0, 0, len(nums) - 1
            
            while j <= n:
                if nums[j] < middle:
                    nums[i], nums[j] = nums[j], nums[i]
                    i += 1
                    j += 1
                elif nums[j] > middle:
                    nums[j], nums[n] = nums[n], nums[j]
                    n -= 1
                else:
                    j += 1
        
        three_way_partition(nums, 1)
