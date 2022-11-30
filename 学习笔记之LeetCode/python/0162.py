class Solution:
    def findPeakElement1(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        
        while left < right:
            middle = int( (left + right) / 2)
            
            if nums[middle] > nums[middle + 1]:
                right = middle
            else:
                left = middle + 1
        
        return left        

    def findPeakElement(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        def helper(nums, left, right):
            if left == right:
                return left
            
            middle = int( (left + right) / 2 )
            
            if nums[middle] > nums[middle + 1]:
                return helper(nums, left, middle)
            else:
                return helper(nums, middle + 1, right)
    
        return helper(nums, 0, len(nums) - 1)
