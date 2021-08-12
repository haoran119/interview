class Solution:
    # Backtracking
    def subsets(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return None
        
        n_nums = len(nums)
        results = []
        
        def helper(index, path):
            results.append(path)
            
            for i in range(index, n_nums):
                helper( i + 1, path + [ nums[ i ] ] )
        
        helper(0, [])
        
        return results        

    # Iterative
    def subsets2(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return None
        
        results = [ [] ]
        
        for num in nums:
            results += [ item + [ num ] for item in results ]
        
        return results

    # Bit manipulation
    def subsets3(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return None
        
        results = []
        
        # check each subset
        for i in range( 1 << len( nums ) ):
            current = []

            # check if nums[j] is in current subset
            for j in range( len( nums) ):
                if (i >> j) & 1:
                    current.append( nums[ j ] )

            results.append(current)
        
        return results
