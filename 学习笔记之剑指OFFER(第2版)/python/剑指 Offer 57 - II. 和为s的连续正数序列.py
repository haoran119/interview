class Solution:
    # Sliding window
    # find all windows where sum of the sequence in the window equals to target
    # Time O(target) / Space O(1)
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        if target < 3:
            return []
        
        # initialise sliding window
        left, right, current_sum = 1, 2, 3
        results = []

        # at lease 2 nums in the sequence 
        while left <= target // 2:
            if current_sum < target:
                # move window right side to add bigger num
                right += 1
                current_sum += right
            elif current_sum > target:
                # move window left side to subtract smaller num
                current_sum -= left
                left += 1
            else:
                # find one result
                current_result = list(range(left, right + 1))
                results.append(current_result)
                # move window left side for next sequence
                current_sum -= left
                left += 1
        
        return results
