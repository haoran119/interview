class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not word:
            return False
        
        visited = [ [ False for j in range( len( board[ 0 ] ) ) ] for i in range( len( board ) ) ] # remember the way
        
        def helper(x, y, current):
            if current == len( word ):
                return True
            
            if x < 0 or x >= len( board ) or y < 0 or y >= len( board[ 0 ] ) or visited[x][y] or board[x][y] != word[current]:
                return False
            
            visited[x][y] = True
            
            result = (helper(x - 1, y, current + 1) 
                    or helper(x + 1, y, current + 1) 
                    or helper(x, y - 1, current + 1) 
                    or helper(x, y + 1, current + 1) )
            
            visited[x][y] = False
            
            return result
        
        for i in range( len( board ) ):
            for j in range( len ( board[ 0 ] ) ):
                if helper(i, j, 0):
                    return True
        
        return False
