class Solution:
    # Hash
    def firstUniqChar(self, s: str) -> str:
        if not s:
            return ' '
        
        # A Counter is a dict subclass for counting hashable objects.
        frequency = collections.Counter(s)
        for _, c in enumerate(s):
            if frequency[c] == 1:
                return c

        return ' ' 
