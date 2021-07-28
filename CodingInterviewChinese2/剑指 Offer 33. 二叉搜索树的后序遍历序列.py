class Solution:
    # Recursion
    # verify that the last node in postorder is the root node, 
    # all left subtree nodes < root, and all right subtree nodes > root
    def verifyPostorder(self, postorder: List[int]) -> bool:
        if not postorder:
            return True

        def dfs(start: int, end: int) -> bool:
            if start >= end:
                return True

            # last node is the root node in postorder
            root = postorder[end]

            index = start
            # left subtree nodes < root
            while index < end and postorder[index] < root:
                index += 1
            middle = index
            # right subtree nodes > root
            while index < end and postorder[index] > root:
                index += 1
            
            # pay attention to the index
            return index == end and dfs(start, middle - 1) and dfs(middle, end - 1)

        return dfs(0, len(postorder) - 1)
