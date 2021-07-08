class Solution:
    def fib(self, n: int) -> int:
        a, b = 0, 1

        for _ in range(n):
            a, b = b, a + b

        # In Py3 the plain int type is unbounded
        return a % 1000000007
