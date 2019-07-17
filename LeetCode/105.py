# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        idx = inorder.index( preorder.pop( 0 ) )
        
        node = TreeNode( inorder[ idx ] )
        
        node.left = buildTree( preorder, inorder[ 0:idx ] )
        node.right = buildTree( preorder, inorder[ idx+1: ] )
        
        return node        
