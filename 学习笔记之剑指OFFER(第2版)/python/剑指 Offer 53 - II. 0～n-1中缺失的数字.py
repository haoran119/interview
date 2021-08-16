class Solution:
    # Binary search
    # nums consists of two parts where left section nums[i]==i and right section nums[i]!=i
    # Target is to find the first num of right section
    # Time O(logN) / Space O(1)
    def missingNumber(self, nums: List[int]) -> int:
        if not nums:
            return
        
        left, right = 0, len(nums) - 1

        # need to use <= for test case [0]
        while left <= right:
            middle = (right - left) // 2 + left
            if nums[middle] == middle:
                # search first num of right section in [middle + 1, right]
                left = middle + 1
            else:
                # search last num of left section in [left, middle - 1]
                right = middle - 1
        
        # left is the first num of right section
        # right is the last num of left section
        return left
