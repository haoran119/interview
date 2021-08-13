from typing import List

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if (not board) or (not word):
            return False

        visited = [ [ False for _ in range(len(board[0])) ] for _ in range(len(board)) ]

        def dfs(row, column, depth):
            # pay attention to the not operator
            if (not 0 <= row < len(board)) or (not 0 <= column < len(board[0]) or (board[row][column] != word[depth])
                or visited[row][column]):
                return False

            if depth == len(word) - 1:
                return True

            visited[row][column] = True
            result = (dfs(row + 1, column, depth + 1) or dfs(row - 1, column, depth + 1)
                      or dfs(row, column + 1, depth + 1) or dfs(row, column - 1, depth + 1))
            visited[row][column] = False

            return result

        for i in range(len(board)):
            for j in range(len(board[0])):
                if dfs(i, j, 0):
                    return True

        return False


if __name__ == '__main__':
    mySolution = Solution()

    board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
    word = "ABCCED"

    print(mySolution.exist(board, word))
