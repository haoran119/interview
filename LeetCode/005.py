class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""
        
        if len( s ) == 1:
            return s
        
        n_s = len( s )
        start, maxlen = 0, 1
        i = 0
        
        while i < n_s:
            if n_s - i <= maxlen / 2:
                break;
                
            left = right = i
            
            # move right point as duplicate chars is the center of palindromic substring
            while ( right + 1 < n_s ) and ( s[ right ] == s[ right + 1 ] ):
                right += 1
            
            # start point of next loop
            i = right + 1
                        
            # expand left and right points
            while ( left > 0 ) and ( right + 1 < n_s ) and ( s[ left - 1 ] == s[ right + 1 ] ):
                left -= 1
                right += 1
                
            if right - left + 1 > maxlen:
                maxlen = right - left + 1
                start = left

        # pay attention to slicing
        return s[ start : start + maxlen ]        
