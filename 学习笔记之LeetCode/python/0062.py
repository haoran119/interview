class Solution:
    def uniquePaths1(self, m: int, n: int) -> int:
        dp = [ [ 1 for x in range(n) ] for x in range(m) ]
        
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        
        return dp[m - 1][n - 1]        

    def uniquePaths2(self, m: int, n: int) -> int:
        previous, current = [1] * n, [1] * n
        
        for i in range(1, m):
            for j in range(1, n):
                current[j] = previous[j] + current[j - 1]
            
            current, previous = previous, current
        
        # note : previous not current
        return previous[n - 1]
    
    def uniquePaths(self, m: int, n: int) -> int:
        current = [1] * n
        
        for i in range(1, m):
            for j in range(1, n):
                current[j] += current[j - 1]
        
        return current[n - 1]
