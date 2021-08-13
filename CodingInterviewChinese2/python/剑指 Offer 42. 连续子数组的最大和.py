class Solution:
    # DP
    # f[i] = { max( f[i - 1] + nums[i], nums[i] ) }
    # f[0] = nums[0], target f[n - 1]
    def maxSubArray(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        result = nums[0]
        previous = 0

        for num in nums:
            # use previous to replace f[i-1] to save space consumption
            previous = max(previous + num, num)
            result = max(result, previous)
        
        return result
