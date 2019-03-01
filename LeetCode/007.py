class Solution:
    def reverse(self, x: int) -> int:
        result = 0
        sign = 1
        
        if x < 0:
            sign = -1
            x = abs(x)
            
        while x != 0:
            if result > ( 2**31 - ( x % 10 ) ) // 10: # be careful of floor division (integer division)
                return 0
            
            result = result * 10 + x % 10
            x //= 10 # be careful of floor division (integer division)
        
        return result * sign
    
    def reverse2(self, x: int) -> int:    
        # [begin:end:step] - leaving begin and end off and specifying a step of -1, it reverses a string.
        s = str( abs( x ) )
        x_reverse = int( s[ ::-1 ] ) if x > 0 else (- int( s[ ::-1 ] ) )
        
        if ( ( x_reverse >= - 2**31 ) and ( x_reverse <= 2**31 - 1 ) ):
            return x_reverse
        else:
            return 0
