class Solution:
    # DP Top down with memoization table
    def coinChange1(self, coins: List[int], amount: int) -> int:
        if amount < 1:
            # should be 0 rather than -1
            return 0
        
        counts = [0] * (amount + 1)
        
        def helper(amount):
            if amount == 0:
                return 0
            
            if counts[amount] != 0:
                return counts[amount]
            
            min_result = float('inf')
            
            for coin in coins:
                if amount < coin:
                    continue
                    
                result = helper(amount - coin) + 1
                
                if 0 < result < min_result:
                    min_result = result
            
            counts[amount] = -1 if min_result == float('inf') else min_result
            
            return counts[amount]
        
        return helper(amount)

    # DP Bottom up
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount < 1:
            # should be 0 rather than -1
            return 0
        
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0
        
        for i in range(0, amount + 1):
            for coin in coins:
                if i >= coin:
                    dp[i] = min(dp[i], dp[i - coin] + 1)
        
        return dp[amount] if dp[amount] != float('inf') else -1
