class Solution:
    # DP
    # define f[i] as the count of translations of num[0:i]
    # f[i] = {f[i-1] + f[i-2] if 10 <= num[i-2:i] <= 25; f[i-1] otherwise}
    # initiate f[0] = 1, target f[N]
    # Time complexity O(logN) : digit of N
    # Could use scrolling array to optimise the space complexity to O(1)
    def translateNum1(self, num: int) -> int:
        if num is None:
            return 0
        
        strs = str(num)
        f = [0 for _ in range(len(strs) + 1)]
        f[0], f[1] = 1, 1

        for i in range(2, len(strs) + 1):
            s_temp = strs[i - 2 : i]
            f[i] = f[i - 1] + f[i - 2] if '10' <= s_temp <= '25' else f[i - 1]
        
        return f[len(strs)]

    def translateNum(self, num: int) -> int:
        if num is None:
            return 0
        
        strs = str(num)
        # use scrolling array to replace f[]
        previous_2, previous_1 = 1, 1

        for i in range(2, len(strs) + 1):
            s_temp = strs[i - 2 : i]
            current = previous_1 + previous_2 if '10' <= s_temp <= '25' else previous_1
            previous_2 = previous_1
            previous_1 = current
        
        return previous_1
