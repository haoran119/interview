class Solution:
    def lengthOfLIS1(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        dp = [1] * len(nums)
        
        for i in range(len(nums)):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
            
        # should be the maximum element of dp
        return max(dp)

    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        tails = []
        
        for num in nums:
            left, right = 0, len(tails) - 1
            
            # find the first index "left" where tails[left] >= num
            while left <= right:
                middle = (left + right) // 2
                if num <= tails[middle]:
                    right = middle - 1
                else:
                    left = middle + 1
            
            # if num is larger than all tails, append it
            if left == len(tails):
                tails.append(num)
            # if tails[left-1] < num <= tails[left], update tails[left]
            else:
                tails[left] = num
        
        return len(tails)
