# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # recursion
    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:
            return True

        def is_tree_symmtric(root1: TreeNode, root2: TreeNode) -> bool:
            if root1 is None and root2 is None:
                return True
            
            if root1 is None or root2 is None:
                return False

            if root1.val != root2.val:
                return False

            return is_tree_symmtric(root1.left, root2.right) and is_tree_symmtric(root1.right, root2.left)

        return is_tree_symmtric(root, root)
