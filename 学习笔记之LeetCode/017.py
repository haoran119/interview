class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        
        self._mapping = ['', '', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        results = []
        self.helper(results, digits, '', 0)
        
        return results
        
    def helper(self, results: list, digits: str, current: str, n: int):
        if n == len(digits):
            results.append(current)
        else:
            for ch in self._mapping[int(digits[n])]:
                self.helper(results, digits, current + ch, n + 1)        
