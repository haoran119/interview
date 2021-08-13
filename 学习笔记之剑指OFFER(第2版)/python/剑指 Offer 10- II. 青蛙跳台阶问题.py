class Solution:
    # f(n) = f(n-1) + f(n-2)
    def numWays(self, n: int) -> int:
        a, b = 1, 1

        for _ in range(n):
            a, b = b, a + b
    
        # In PY3 the plain int type is unbounded
        return a % 1000000007
