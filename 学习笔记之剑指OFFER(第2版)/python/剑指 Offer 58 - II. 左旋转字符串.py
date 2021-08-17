class Solution:
    # string slice
    # Time O(N) / Space O(N)
    def reverseLeftWords1(self, s: str, n: int) -> str:
        return s[n:] + s[:n]

    # string join
    # Time O(N) / Space O(N)
    def reverseLeftWords2(self, s: str, n: int) -> str:
        if not s:
            return s
        
        results = []

        for i in range(n, len(s)):
            results.append(s[i])
        for i in range(0, n):
            results.append(s[i])
        
        return ''.join(results)
    
    # reverse string three times
    # Time O(N) / Space O(N)
    def reverseLeftWords(self, s: str, n: int) -> str:
        if not s:
            return s

        strs = list(s)

        def reverse(left: int, right: int):
            while left < right:
                strs[left], strs[right] = strs[right], strs[left]
                left += 1
                right -= 1
        
        # reverse first n characters
        reverse(0, n - 1)
        # reverse last len(s) - n characters
        reverse(n, len(s) - 1)
        # reverse the whole str
        reverse(0, len(s) - 1)

        return ''.join(strs)
