# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # Customerised Inorder tree traversal (right -> root -> left) to find the kth node in reverse
    # Time O(N) / Space O(N)
    def kthLargest(self, root: TreeNode, k: int) -> int:
        if root is None or k == 0:
            return
        
        # need to use instance variable
        self.result, self.count = 0, k
        
        def dfs(node: TreeNode):
            if node is None or self.count == 0:
                return
            
            dfs(node.right)

            self.count -= 1
            if self.count == 0:
                self.result = node.val
                return
            
            dfs(node.left)

        # inorder tree traversal        
        dfs(root)

        return self.result
