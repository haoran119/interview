class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        min_num, a, b = float("inf"), float("inf"), float("inf")
        
        for c in nums:
            if c <= min_num: # pay attention to equal case
                min_num = c
            elif c <= b:
                a, b = min_num, c
            else: # a < b < c
                return True
        
        return False
