class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if nums is None:
            return [-1, -1]
        
        def helper(nums, target, search_left_index):
            left, right = 0, len(nums)
            
            while left < right:
                middle = (left + right) // 2
                
                # check if searching the leftmost index or not
                if nums[middle] > target or (search_left_index and nums[middle] == target):
                    right = middle
                else:
                    left = middle + 1
            
            return left
        
        left_index = helper(nums, target, True)
        
        if left_index == len(nums) or nums[left_index] != target:
            return [-1, -1]
        
        return [ left_index, helper( nums, target, False ) - 1 ]
