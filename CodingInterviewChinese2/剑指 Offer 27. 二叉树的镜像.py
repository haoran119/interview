# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # recursion
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        if root is None:
            return None
        
        # check if it is the leaf
        if root.left is None and root.right is None:
            return root
        
        left_node = self.mirrorTree(root.left)
        right_node = self.mirrorTree(root.right)
        root.left = right_node
        root.right = left_node

        return root
