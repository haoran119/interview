class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        
        self.x = len(grid)
        self.y = len(grid[0])
        count = 0
        
        for i in range(self.x):
            for j in range(self.y):
                if grid[i][j] == '1':
                    self.DFS(grid, i, j)
                    count += 1
        
        return count
                
    def DFS(self, g: List[List[str]], x: int, y: int):
        if x < 0 or x >= self.x or y < 0 or y >= self.y or g[x][y] == '0':
            return
        
        g[x][y] = '0'
        
        self.DFS(g, x - 1, y)
        self.DFS(g, x + 1, y)
        self.DFS(g, x, y - 1)
        self.DFS(g, x, y + 1)
