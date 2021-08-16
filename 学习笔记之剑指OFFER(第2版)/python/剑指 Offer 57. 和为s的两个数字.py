class Solution:
    # Two pointers
    # Time O(N) / Space O(1)
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        if not nums or target is None:
            return []
        
        left, right = 0, len(nums) - 1

        while left < right:
            s = nums[left] + nums[right]            
            if s > target:
                # reduce big num
                right -= 1
            elif s < target:
                # increase small num
                left += 1
            else:
                return nums[left], nums[right]
        
        return []
