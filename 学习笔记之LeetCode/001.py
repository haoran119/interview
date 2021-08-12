class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict = {}
        
        for id, num in enumerate( nums ):            
            if dict.get( target - num ) is not None:
                return [ id, dict[ target - num ] ]
            else:            
                dict[ num ] = id
