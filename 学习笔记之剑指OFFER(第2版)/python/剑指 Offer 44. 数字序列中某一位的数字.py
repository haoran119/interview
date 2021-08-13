class Solution:
    # Math
    # define start as 10^(digit-1), e.g. 1, 10, 100...
    # count of single digit number on certain digit = 9 * start * digit, 
    # e.g. for the section 100 ~ 999, count = 9 * 100 * 3
    # To calculate the corresponding Nth digit number, we need to :
    # 1. figure out the digit number section;
    # 2. figure out the number on the section;
    # 3. figure out which digit of the number.
    def findNthDigit(self, n: int) -> int:
        digit, start, count = 1, 1, 9

        # calculate which digit number section is
        while n > count:
            # subtract count of previous digit number
            n -= count
            # move to the higher digit
            digit += 1
            start *= 10
            # count of the current digit number
            count = 9 * start * digit
        
        # calculate which number on the digit section is
        num = start + (n - 1) // digit

        # calculate which digit of the number is
        s = str(num)
        result = int(s[(n - 1) % digit])

        return result
