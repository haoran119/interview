class Solution:
    # 顺子需满足如下条件
    # 1. 除大小王外，所有牌无重复；
    # 2. 5张牌中最大的牌max，最小的牌min（大小王除外），则需满足：max - min < 5
    # Time O(N) / Space O(N)
    def isStraight1(self, nums: List[int]) -> bool:
        cards = set()
        # pay attention to the initial values
        max_num, min_num = 0, 14

        for num in nums:
            # skip joker
            if num == 0:
                continue
            
            # condition 1 not repeated
            if num in cards:
                return False
            else:
                cards.add(num)
            
            max_num = max(max_num, num)
            min_num = min(min_num, num)
        
        # condition 2
        return max_num - min_num < 5

    # Sort 
    # Time O(N) / Space O(N)
    def isStraight(self, nums: List[int]) -> bool:
        if len(nums) != 5:
            return False

        nums.sort()
        n_joker = 0

        for i in range(4):
            # do with joker separately
            if nums[i] == 0:
                n_joker += 1
            # condition 1 not repeated
            elif nums[i] == nums[i + 1]:
                return False

        # condition 2
        return nums[4] - nums[n_joker] < 5
