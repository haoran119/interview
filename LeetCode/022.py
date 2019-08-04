class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0:
            return None
        
        result = []
        
        def helper(s = '', left = 0, right = 0):
            if len(s) == 2 * n:
                result.append(s)
                return
            
            if left < n:
                helper(s + '(', left + 1, right)
            
            if right < left:
                helper(s + ')', left, right + 1)
        
        helper()
        return result        
