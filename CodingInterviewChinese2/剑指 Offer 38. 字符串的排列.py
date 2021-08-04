class Solution:
    # DFS + pruning away duplicate branches
    def permutation(self, s: str) -> List[str]:
        if not s:
            return []
        
        n = len(s)
        results = []
        visited = [False for _ in range(n)]

        def dfs(step: int, result: str):
            if step == n:
                results.append(result)
            
            for i in range(n):
                # ensure that only the first char in duplicates will be visited
                if (visited[i] or (i > 0 and not visited[i - 1] and s_sorted[i - 1] == s_sorted[i])):
                    continue
                
                visited[i] = True
                dfs(step + 1, result + s_sorted[i])
                visited[i] = False
        
        # sort letters in string alphabetically
        s_sorted = ''.join(sorted(s))
        dfs(0, '')

        return results
