class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        d = dict()  # current index of character        
        left, right, maxlen = 0, 0, 0
        n = len(s)
        
        while right < n:
            # if char in dict[j']，skip all the elements in the range [i,j'] and let i to be j'+1 directly.
            if s[ right ] in d:
                left = max( d[ s[ right ] ], left ) 

            maxlen = max( right - left + 1, maxlen )

            # set next available index for left, i.e. j'+1
            d[ s[ right ] ] = right + 1

            right += 1
                
        return maxlen
    
    def lengthOfLongestSubstring1(self, s: str) -> int:
        dict = set()
        
        n = len(s)
        left, right, maxlen = 0, 0, 0
        
        while right < n:
            if s[ right ] not in dict:
                dict.add( s[ right ] )
                maxlen = max( maxlen, right - left + 1 )
                right += 1
            else:
                dict.remove( s[ left ] )
                left += 1                
                
        return maxlen
