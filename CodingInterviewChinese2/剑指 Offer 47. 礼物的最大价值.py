class Solution:
    # DP
    # define f[i][j] as the max value from upper left corner to grid[i][j] 
    # f[i][j] = max{f[i-1][j], f[i][j-1]} + grid[i][j]
    # target f[m][n]
    def maxValue(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return 0
        
        m, n = len(grid), len(grid[0])
        # add one extra row and column for grid[0][] and grid[][0]
        # define f[i][j] as the max value from upper left corner to grid[i-1][j-1]
        f = [[0 for _ in range(n + 1)] for _ in range(m + 1)]

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + grid[i - 1][j - 1]
        
        return f[-1][-1]
      
