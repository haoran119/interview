class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        merge_nums = sorted( nums1 + nums2 ) # pay attention to the parameter
        
        n_nums = len( merge_nums )
        index = int( n_nums / 2 )
        
        if n_nums % 2 == 0:    
            return ( merge_nums[ index ] + merge_nums[ index - 1 ] ) / 2
        else:
            return ( merge_nums[ index ] )
