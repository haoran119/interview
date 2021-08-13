class Solution:
    # sliding window
    # make sure that no duplicate characters in the window
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0

        # record the last position of the character
        dict_left_index = {}
        result, left = 0, -1

        for right in range(len(s)):
            # update window left bound to slide window if window right char is duplicated 
            if s[right] in dict_left_index:
                left = max(left, dict_left_index.get(s[right]))
            dict_left_index[s[right]] = right

            result = max(result, right - left)

        return result
