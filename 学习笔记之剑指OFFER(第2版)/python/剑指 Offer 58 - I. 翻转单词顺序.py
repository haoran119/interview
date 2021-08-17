class Solution:
    # Two pointers to handle string
    # Time O(N) / Space O(N)
    def reverseWords1(self, s: str) -> str:
        # remove the leading and trailing characters
        s = s.strip()

        # move pointers from end to start
        left, right = len(s) - 1, len(s) - 1
        results = []

        while left >= 0:
            # search the next whitespace to split words
            while left >= 0 and s[left] != ' ':
                left -= 1 
            # add words to results in reverse
            results.append(s[left + 1: right + 1])
            # skip whitespace between words
            while left >= 0 and s[left] == ' ':
                left -= 1
            # move right pointer to the end of the word
            right = left
        
        # join words
        return ' '.join(results)

    # String
    # Time O(N) / Space O(N)
    def reverseWords(self, s: str) -> str:
        # remove the leading and trailing characters
        s = s.strip()
        # return a list of the words in the string, using sep as the delimiter string.
        words = s.split()
        # return a reverse iterator.
        # reversed_words = reversed(words)
        reversed_words = words[::-1]

        # join words
        return ' '.join(reversed_words)
