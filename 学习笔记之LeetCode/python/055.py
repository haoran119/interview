class Solution:
    def canJump1(self, nums: List[int]) -> bool:
        lastpos = len(nums) - 1
        
        for i in range(len(nums) - 1, -1, -1):
            if i + nums[i] >= lastpos:
                lastpos = i
        
        return lastpos == 0

    def canJump(self, nums: List[int]) -> bool:
        f = [0] * len(nums)
        f[0] = nums[0]
        
        for i in range(1, len(nums)):
            if f[i - 1] < i:
                return False
            
            f[i] = max(f[i - 1], i + nums[i])
        
        return f[-1] >= len(nums) - 1
