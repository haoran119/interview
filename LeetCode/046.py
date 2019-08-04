class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return None
        
        result = []
        used = [False] * len(nums)
        
        def helper(current, n):
            if n == 0:
                result.append(current[:]) # pay attention to [:]
                return
            
            for i in range( len( nums ) ):
                if not used[i]:
                    used[i] = True
                    current.append( nums[i] )
                    
                    helper(current, n - 1)
                    
                    current.pop()
                    used[i] = False
        
        helper([], len(nums))
        
        return result        
