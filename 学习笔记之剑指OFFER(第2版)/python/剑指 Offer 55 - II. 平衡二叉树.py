# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # DFS
    # Post-order tree traversal to check from bottom to top to avoid duplicate check
    # Time O(N) / Space O(N)
    def isBalanced(self, root: TreeNode) -> bool:
        if root is None:
            return True
        
        def depth(node: TreeNode) -> int:
            if node is None:
                return 0
            
            # check subtree depth first
            left_depth = depth(node.left)
            right_depth = depth(node.right)
            
            # return root depth
            if left_depth == -1 or right_depth == -1 or abs(left_depth - right_depth) > 1:
                # subtree is not balanced
                return -1
            else:
                return max(left_depth, right_depth) + 1
        
        return depth(root) >= 0
