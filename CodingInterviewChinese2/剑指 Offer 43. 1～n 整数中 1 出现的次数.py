class Solution:
    # Math
    # define N = N[m]N[m-1]...N[i]...N[2]N[1]
    # N[i] is the current digit number, 10^i is the digit
    # N[m]N[m-1]...N[i+1] is the high digit number
    # N[i-1]...N[2]N[1] is the low digit number
    # The occurrence of 1 on a certain digit = {high * digit if current = 0;
    # high * digit + low + 1 if current = 1;
    # (high + 1 ) * digit if current > 1} 
    # Iterate the digit from 1 to 10^m to sum the occurrence of 1 on each digit to get the result
    def countDigitOne(self, n: int) -> int:
        result = 0
        # start from the 1 digit number
        digit = 1
        high, current, low = n // 10, n % 10, 0

        while high != 0 or current != 0:
            if current == 0:
                result += high * digit
            elif current == 1:
                result += high * digit + low + 1
            else:
                result += (high + 1) * digit
            
            # move to the left higher digit
            low += current * digit
            current = high % 10
            high //= 10
            digit *= 10
        
        return result
        
