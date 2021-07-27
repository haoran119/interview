class Solution:
    # Simulation
    # start from the left-upper corner to print number in grid
    # if it is beyond the bound, then move clockwise
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        # return [] for empty matrix
        if not matrix or not matrix[0]:
            return []

        n_row, n_column = len(matrix), len(matrix[0])
        visited = [[False] * n_column for _ in range(n_row)]
        n_number = n_row * n_column

        row, column = 0, 0
        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        direction_index = 0
        list_result = []

        for _ in range(n_number):
            list_result.append(matrix[row][column])
            visited[row][column] = True

            # move clockwise if it will move beyond the bound
            next_row = row + directions[direction_index][0]
            next_column = column + directions[direction_index][1]
            if not (0 <= next_row < n_row and 0 <= next_column < n_column and 
                    not visited[next_row][next_column]):
                direction_index = (direction_index + 1) % 4
            
            row += directions[direction_index][0]
            column += directions[direction_index][1]
        
        return list_result
