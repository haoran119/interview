class Solution:
    # Binary search
    # left index is to find the index of first num >= target
    # right index is to find the index - 1 of the first num > target
    # Time O(logN) / Space O(1)
    def search(self, nums: List[int], target: int) -> int:
        if not nums or target is None:
            return 0
        
        def helper(t: int, equal: bool) -> int:
            left, right = 0, len(nums) - 1
            result = len(nums)

            while left <= right:
                middle = (right - left) // 2 + left
                if nums[middle] > t or (equal and nums[middle] >= t):
                    right = middle - 1
                    result = middle
                else:
                    left = middle + 1
            
            return result
        
        left_index = helper(target, True)
        right_index = helper(target, False) - 1

        # check if target is hit
        if (left_index <= right_index < len(nums) and nums[left_index] == target 
            and nums[right_index] == target):
            return right_index - left_index + 1
        
        return 0
